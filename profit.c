#include <stdio.h>

int main() {
    char customerName[50];
    int numItems;
    float subTotal = 0;
    float taxRate = 13.0; 

    char itemNames[50][50];
    float itemPrices[50];
    int itemQuantities[50];

    printf("--- KC A to Z Kirana Pasal Billing ---\n");
    printf("Customer Name: ");
    scanf(" %[^\n]s", customerName);

    printf("How many different items? ");
    scanf("%d", &numItems);

    for(int i = 0; i < numItems; i++) {
        printf("\nItem %d name: ", i + 1);
        // This line allows spaces (like "Momo Masala")
        scanf(" %[^\n]s", itemNames[i]);
        
        printf("Price per unit: ");
        scanf("%f", &itemPrices[i]);
        
        printf("Quantity: ");
        scanf("%d", &itemQuantities[i]);
        
        subTotal += (itemPrices[i] * itemQuantities[i]);
    }

    float vatAmount = (subTotal * taxRate) / 100;
    float grandTotal = subTotal + vatAmount;

    printf("\n\n==============================\n");
    printf("     FINAL INVOICE\n");
    printf("==============================\n");
    printf("Customer: %s\n", customerName);
    printf("------------------------------\n");
    printf("Item\t\tQty\tTotal\n");

    for(int i = 0; i < numItems; i++) {
        printf("%s\t\t%d\t%.2f\n", 
                itemNames[i], 
                itemQuantities[i], 
                itemPrices[i] * itemQuantities[i]);
    }

    printf("------------------------------\n");
    printf("Sub-Total:    NPR %.2f\n", subTotal);
    printf("VAT (13%%):    NPR %.2f\n", vatAmount);
    printf("Grand Total:  NPR %.2f\n", grandTotal);
    printf("==============================\n");

    return 0;
}