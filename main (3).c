/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define NUM_CARS 20
#define TIP_PERCENTAGE 0.02
struct customer {   //customer information is store in a stucture call car
    char first_name[15];
    char last_name[15];
    int day;
    int month;
    int year;
    int service;
    int visit;
    char license[7];
};

    struct customer cars[NUM_CARS];  // array to represent cars in wash bay
    int num_customers = 0;  // number of customers
    int num_wash=0;// number of cars wash
    double total_cost = 0.0;
    double tip_amount = 0.0;
    double grand_total = 0.0;
    int p_option;
    float discount;
     float final_price;
    char tip;
    char choi;
    int choice;                // user choice to continue or exit
     
   int count_service(struct customer cars[], int num_customers, int service_type) {
    int count = 0;
    for (int i = 0; i < num_customers; i++) {
        if (cars[i].service == service_type) {
            count++;
        }
    }
    return count;
}

   void add_customer() {
   
    // get number of customers and their cars
    while (num_customers < NUM_CARS) {
        printf("\nEnter customer information for car %d:\n", num_customers + 1);
        printf("Enter transaction date (dd/mm/yyyy): ");
        scanf("%d/%d/%d", &cars[num_customers].day, &cars[num_customers].month, &cars[num_customers].year);
        printf("Enter customer first name: ");
        scanf("%s", cars[num_customers].first_name);
        printf("Enter customer last name: ");
        scanf("%s", cars[num_customers].last_name);
       
        do {
            printf("Enter license plate (4 digits followed by 1 or 2 capital letters): ");
            scanf("%s", cars[num_customers].license);
            int len = strlen(cars[num_customers].license);
            if (len == 6 && isupper(cars[num_customers].license[len-1]) && isupper(cars[num_customers].license[len-2])) {
                int digit = 1;
                for (int n = 0; n < 4; n++) {
                    if (!isdigit(cars[num_customers].license[n])) {
                        digit = 0;
                        break;
                    }
                }
                if (digit) {
                    printf("License plate is valid.\n");
                    break;
                } else {
                    printf("License plate must have 4 digits followed by 1 or 2 capital letters.\n");
                }
            } else {
                printf("License plate must have 4 digits followed by 1 or 2 capital letters.\n");
            }
        } while (1);
        
        cars[num_customers].visit = 1;
    
    for (int i = 0; i < num_customers; i++) {
        if (strcmp(cars[i].first_name, cars[num_customers].first_name) == 0) {
            cars[i].visit++;
            printf("Welcome back, %s! You have visited %d times.\n", cars[i].first_name, cars[i].visit);
             break;
        }
    }num_customers++;
        printf("Services Menu:\n");
        printf("1. Wash and Vacuum - $2500.00\n");
        printf("2. Engine Wash - $2000.00\n");
        printf("3. Polishing - $3500.00\n");
        printf("4. Buffing - $5500.00\n");
        printf("5. Roof Cleaning - $3200.00\n");
        printf("6. Detailing/Interior Shampooing - $7500.00\n");
        printf("Enter service (1-6): ");
        scanf("%d", &cars[num_customers].service);
         switch(cars[num_customers].service)
         {
             case 1:{
                 printf("\nYou have selected Wash and Vacuum\n");
                 printf("Your total is: $2500\n");
                 printf("\nIs customer using card or cash? \n 1 for Card and 2 for Cash:\n ");
                 scanf("%d",&p_option);
                 if(p_option==1)
                 {
                 total_cost+=2500 + 75;
                 }
                 else {
                     total_cost+=2500;
                 }
                 break;
             }
             case 2:{
                 printf("You have selected Engine Wash");
                 printf("Your total is: $2000\n");
                 printf("\nIs customer using card or cash? \n 1 for Card and 2 for Cash:\n ");
                 scanf("%d",&p_option);
                  if(p_option==1)
                 {
                 total_cost+=2000 + 60;
                 }
                 else {
                     total_cost+=2000;
                 }
                
                 break;
             }
             case 3:{
                 printf("You have selected Polishing");
                 printf("Your total is: $3500\n");
                 printf("\nIs customer using card or cash? \n 1 for Card and 2 for Cash:\n ");
                 scanf("%d",&p_option);
                  if(p_option==1)
                 {
                 total_cost+=3500 + 105;
                 }
                 else {
                     total_cost+=3500;
                 }
                
                 break;
             }
             case 4:{
                 printf("You have selected Buffing");
                 printf("Your total is: $5500\n");
                 printf("\nIs customer using card or cash? \n 1 for Card and 2 for Cash:\n ");
                 scanf("%d",&p_option);
                  if(p_option==1)
                 {
                 total_cost+=5500 + 165;
                 }
                 else {
                     total_cost+=5500;
                 }
              
                 break;
             }
             case 5:{
                 printf("You have selected Roof Cleaning");
                 printf("Your total is: $3200\n");
                 printf("\nIs customer using card or cash? \n 1 for Card and 2 for Cash:\n ");
                 scanf("%d",&p_option);
                  if(p_option==1)
                 {
                 total_cost+=3200 + 96;
                 }
                 else {
                     total_cost+=3200;
                 }
               
                 break;
             }
             case 6: {
                 printf("You have selected Detailing/Interior Shampooing");
                 printf("Your total is: $7500\n");
                 printf("\nIs customer using card or cash? \n 1 for Card and 2 for Cash:\n ");
                 scanf("%d",&p_option);
                  if(p_option==1)
                 {
                 total_cost+=7500 + 225;
                 }
                 else {
                     total_cost+=7500;
                 }
                
                 break;
             }
             
         }
         // Ask the user if they want to give a tip
  printf("Would you like to give a tip? (Enter y for yes or n for no)\n");
  
  scanf(" %c", &tip);

  // Calculate the tip amount if the user wants to give a tip
  if (tip == 'y') {
    tip_amount = total_cost * TIP_PERCENTAGE;
  }

  // Calculate the grand total
  grand_total = total_cost + tip_amount;

        if (num_customers == NUM_CARS) {
            printf("Wash bay is full with %d cars.\n", NUM_CARS);
            break;
        }
        printf("Do you want to enter information for another car? (y/n): ");
        scanf(" %c", &choi);
        if (tolower(choi) == 'n') {
            break;
        }
     }
     num_customers++;
   
    // write customer information to file
   FILE *fp;
    fp = fopen("customer.txt", "w+");
    fprintf(fp, "Customer information:\n");
    for (int i = 0; i < num_customers; i++) {
        fprintf(fp, "Customer %d: %s %s License Plate(%s) visit %d total spent %f\n", i+1, cars[i].first_name, cars[i].last_name, cars[i].license, cars[i].visit, grand_total);
        
    }
    fclose(fp);
    printf("Customer information saved to customer.txt.\n");
   
    
        // wash 3 cars at a time
        for (int i = 0; i < num_customers; i += 3) {
            printf("Washing cars: ");
            for (int j = i; j < i+3 && j < num_customers; j++) {
                printf("%s (%s), ", cars[j].first_name, cars[j].license);
                num_wash++;
            }
            printf("\n");
        }
       
        // indicate all cars are washed
        printf("All cars washed!\n");
       
        // display customer information
        printf("Customer information:\n");
        for (int i = 0; i < num_customers; i++) {
            printf("Customer %d: %s %s (%s)\n", i+1, cars[i].first_name, cars[i].last_name, cars[i].license);
             printf("Total cost of services: $%.2f\n", total_cost);
             printf("Grand Total is : $%.2f\n",grand_total);
             printf("Tip percentage: %.0f%%\n", TIP_PERCENTAGE * 100);
          if (tip == 'y') {
          printf("Tip amount: $%.2f\n", tip_amount);
          }
        }
       
       
        // clear wash bay by resetting the array
        for (int i = 0; i < NUM_CARS; i++) {
            cars[i].first_name[0] = '\0';
            cars[i].last_name[0]='\0';
            cars[i].license[0] = '\0';
        }
        num_wash = 0;
        printf("Wash bay cleared!\n");
   }
   
   void read_customers_from_file() {
    // open the file for reading
    FILE *fp = fopen("customer.txt", "r+");
      if (fp == NULL) {
         printf("Error opening file.\n");
        return;
    }
    
    
   
    // close the file
    fclose(fp);
}
void display_recent_customer(struct customer cars[], int num_customers, double grand_total) {

    printf("\nFrequent customers:\n");
    for (int i = 0; i < num_customers; i++) {
        if (cars[i].visit > 1) {
            printf("%s %s: %d visits, total spent %f\n", cars[i].first_name, cars[i].last_name, cars[i].visit,grand_total);
            discount = grand_total * 0.2;
            final_price = grand_total - discount;
             printf("%s gets a 20%% discount! Final price: $%.2f\n", cars[i].first_name, final_price);
        }
    }
}

void disply_report()
{
    printf("\nTotal amount earned for each service:\n");
printf("Wash and Vacuum - $%d\n", count_service(cars, num_customers, 1) * 2500);
printf("Engine Wash - $%d\n", count_service(cars, num_customers, 2) * 2000);
printf("Polishing - $%d\n", count_service(cars, num_customers, 3) * 3500);
printf("Buffing - $%d\n", count_service(cars, num_customers, 4) * 5500);
printf("Roof Cleaning - $%d\n", count_service(cars, num_customers, 5) * 3200);
printf("Detaling/ Interior Shampooing - $%d\n", count_service(cars, num_customers, 6) * 7500);

printf("\nTotal number of customers: %d\n", num_customers);

printf("\nGrand Total earned (excluding tips): $%f\n", total_cost);

if (tip_amount > 0) {
printf("Tip amount: $%f\n", tip_amount);
}

printf("Grand Total earned (including tips): $%f\n", grand_total);

}

int main() {
    srand(time(NULL));
   read_customers_from_file(); 
do {
    printf("Welcome to Trish & Shaun's Auto Wash Services\n");
    printf("Select an option:\n");
    printf("1. Add customer\n");
    printf("2. Display most recent customer\n");
    printf("3. Display sales report\n");
    printf("4. Exit\n");
    printf("Your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            add_customer();
            break;
        case 2:
            display_recent_customer(cars,num_customers,grand_total);
            break;
        case 3:
            disply_report();
            break;
        case 4:
            printf("Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
} while (choice != 4);
return 0;
}

