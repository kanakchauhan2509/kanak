#include <stdio.h>
#include <string.h>
int main() {
    
    int id[] = {101, 102, 301, 302, 501, 502, 701, 702, 901, 902};
    
    char item[][20] = {
        "rice", "sugar", "T-shirt", "jeans", "shoes", 
        "milk", "notebook", "coke", "chips", "soap"
    };
    
    char brand[][20] = {
        "India gate", "Madhur", "Allen Solly", "Levi's", "Bata", 
        "Amul", "Classmate", "Coca-Cola", "Lay's", "Dove"
    };
    
    char size[][10] = {
        "5Kg", "1Kg", "M", "32", "8", 
        "500ml", "A4", "750ml", "200g", "180g"
    };
    
    int stock[] = {100, 80, 30, 20, 15, 50, 100, 40, 75, 40};
    float mrp[] = {450, 55, 799, 1999, 2499, 32, 60, 45, 20, 180};
    int discount[] = {10, 5, 20, 15, 25, 5, 10, 15, 5, 10};
    
    int totalItems = 10;
    
    
    int cart_id[10] = {0};
    int cart_qty[10] = {0};
    int cart_count = 0;
    
    int choice;
    
    do {
        
        printf("\n\t\t\t******DMART INVOICE******\n");
        printf("\t\t\t 1. Stock Availability\n");
        printf("\t\t\t 2. Purchase Item\n");
        printf("\t\t\t 3. Checkout & Exit\n");
        printf("\t\t\t Enter your choice: ");
        scanf("%d", &choice);
        
        
        while (choice < 1 || choice > 3) {
            printf("\n\t\t\tInvalid choice!\n");
            printf("\t\t\t 1. Stock Availability\n");
            printf("\t\t\t 2. Purchase Item\n");
            printf("\t\t\t 3. Checkout & Exit\n");
            printf("\t\t\t Enter your correct choice: ");
            scanf("%d", &choice);
        }
        
        switch (choice) {
            case 1: {
                
                printf("\n--------------------------------------------------------------------------------\n");
                printf("%-5s %-12s %-15s %-8s %-8s %-8s %-10s\n", "ID", "Item", "Brand", "Size", "Stock", "MRP", "Discount");
                printf("--------------------------------------------------------------------------------\n");
                for (int i = 0; i < totalItems; i++) {
                    printf("%-5d %-12s %-15s %-8s %-8d %-8.2f %-d%%\n", 
                           id[i], item[i], brand[i], size[i], stock[i], mrp[i], discount[i]);
                }
                printf("--------------------------------------------------------------------------------\n");
                break;
            }
            
            case 2: {
                
                int p_id, p_qty, found = 0;
                printf("\nEnter Product ID to purchase: ");
                scanf("%d", &p_id);
                
                for (int i = 0; i < totalItems; i++) {
                    if (id[i] == p_id) {
                        found = 1;
                        printf("Item Found: %s (%s) | Available Stock: %d\n", item[i], brand[i], stock[i]);
                        printf("Enter Quantity: ");
                        scanf("%d", &p_qty);
                        
                        if (p_qty <= 0) {
                            printf("Invalid quantity!\n");
                        } else if (p_qty > stock[i]) {
                            printf("Sorry, insufficient stock available!\n");
                        } else {
                            // Deduct from main stock
                            stock[i] -= p_qty;
                            
                            // Check if item already exists in cart
                            int existing_idx = -1;
                            for (int j = 0; j < cart_count; j++) {
                                if (cart_id[j] == p_id) {
                                    existing_idx = j;
                                    break;
                                }
                            }
                            
                            if (existing_idx != -1) {
                                cart_qty[existing_idx] += p_qty;
                            } else {
                                cart_id[cart_count] = p_id;
                                cart_qty[cart_count] = p_qty;
                                cart_count++;
                            }
                            printf("Successfully added %d unit(s) of %s to your cart!\n", p_qty, item[i]);
                        }
                        break;
                    }
                }
                if (!found) {
                    printf("Product ID not found!\n");
                }
                break;
            }
            
            case 3: {
            
                if (cart_count == 0) {
                    printf("\nYour cart is empty. Thank you for visiting DMart!\n");
                    break;
                }
                
                float total_mrp = 0;
                float total_discount_amt = 0;
                float final_bill = 0;
                
                printf("\n================================================================================\n");
                printf("\t\t\t   DMART FINAL INVOICE\n");
                printf("================================================================================\n");
                printf("%-12s %-12s %-6s %-8s %-10s %-10s %-10s\n", "Item", "Brand", "Qty", "MRP", "Total", "Disc %", "Final Price");
                printf("--------------------------------------------------------------------------------\n");
                
                for (int i = 0; i < cart_count; i++) {
                    for (int j = 0; j < totalItems; j++) {
                        if (id[j] == cart_id[i]) {
                            float item_total_mrp = mrp[j] * cart_qty[i];
                            float item_discount_amt = item_total_mrp * ((float)discount[j] / 100.0);
                            float item_final_price = item_total_mrp - item_discount_amt;
                            
                            printf("%-12s %-12s %-6d %-8.2f %-10.2f %-10d %-10.2f\n", 
                                   item[j], brand[j], cart_qty[i], mrp[j], item_total_mrp, discount[j], item_final_price);
                            
                            total_mrp += item_total_mrp;
                            total_discount_amt += item_discount_amt;
                            final_bill += item_final_price;
                        }
                    }
                }
                
                printf("--------------------------------------------------------------------------------\n");
                printf("%-50s Rs. %-10.2f\n", "Total Gross MRP:", total_mrp);
                printf("%-50s Rs. %-10.2f\n", "Total Discount Allowed:", total_discount_amt);
                printf("================================================================================\n");
                printf("%-50s Rs. %-10.2f\n", "NET PAYABLE AMOUNT:", final_bill);
                printf("================================================================================\n");
                printf("\t\t   Thank you for shopping at DMart!\n\n");
                break;
            }
        }
    } while (choice != 3);
    
    return 0;
}