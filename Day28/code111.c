#include <stdio.h>
#include <string.h>

struct Ticket 
{
    int ticketId;
    char passengerName[50];
    char destination[50];
    float fare;
    int isConfirmed;
};

struct Ticket bookingDatabase[100];
int ticketCount = 0;

void bookTicket();
void displayTickets();
void cancelTicket();
void checkStatus();

int main() 
{
    int choice;

    do 
    {
        printf("\n=================================");
        printf("\n--- TICKET BOOKING SYSTEM ---");
        printf("\n=================================");
        printf("\n1. Book New Ticket");
        printf("\n2. Display All Bookings");
        printf("\n3. Cancel Booking");
        printf("\n4. Check Ticket Status");
        printf("\n5. Exit");
        printf("\n=================================");
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                bookTicket();
                break;
            case 2:
                displayTickets();
                break;
            case 3:
                cancelTicket();
                break;
            case 4:
                checkStatus();
                break;
            case 5:
                printf("\nExiting the program. Thank you!\n");
                break;
            default:
                printf("\nInvalid Choice! Please enter a number between 1 and 5.\n");
        }
    } 
    while (choice != 5);

    return 0;
}

void bookTicket() 
{
    struct Ticket newTicket;

    if (ticketCount >= 100) 
    {
        printf("\nBooking storage full! Cannot book more tickets.\n");
        return;
    }

    printf("\nEnter Ticket ID: ");
    scanf("%d", &newTicket.ticketId);
    getchar();

    printf("Enter Passenger Name: ");
    fgets(newTicket.passengerName, 50, stdin);
    newTicket.passengerName[strcspn(newTicket.passengerName, "\n")] = '\0';

    printf("Enter Destination City: ");
    fgets(newTicket.destination, 50, stdin);
    newTicket.destination[strcspn(newTicket.destination, "\n")] = '\0';

    printf("Enter Travel Fare Amount: ");
    scanf("%f", &newTicket.fare);

    newTicket.isConfirmed = 1;

    bookingDatabase[ticketCount] = newTicket;
    ticketCount++;

    printf("\nTicket booked successfully!\n");
}

void displayTickets() 
{
    int i;

    if (ticketCount == 0) 
    {
        printf("\nNo ticket bookings found in system database.\n");
        return;
    }

    printf("\n%-10s %-25s %-25s %-10s %-10s", "Ticket ID", "Passenger Name", "Destination", "Fare", "Status");
    printf("\n---------------------------------------------------------------------------------");
    
    for (i = 0; i < ticketCount; i++) 
    {
        printf("\n%-10d %-25s %-25s %-10.2f %-10s", 
               bookingDatabase[i].ticketId, 
               bookingDatabase[i].passengerName, 
               bookingDatabase[i].destination, 
               bookingDatabase[i].fare, 
               (bookingDatabase[i].isConfirmed == 1) ? "Confirmed" : "Cancelled");
    }
    printf("\n");
}

void cancelTicket() 
{
    int searchId, i, found = 0;

    if (ticketCount == 0) 
    {
        printf("\nNo bookings available to cancel.\n");
        return;
    }

    printf("\nEnter Ticket ID to cancel: ");
    scanf("%d", &searchId);

    for (i = 0; i < ticketCount; i++) 
    {
        if (bookingDatabase[i].ticketId == searchId) 
        {
            found = 1;
            if (bookingDatabase[i].isConfirmed == 0) 
            {
                printf("\nError: This booking is already cancelled!\n");
            } 
            else 
            {
                bookingDatabase[i].isConfirmed = 0;
                printf("\nSuccess: Ticket booking has been cancelled successfully.\n");
            }
            break;
        }
    }

    if (!found) 
    {
        printf("\nTicket ID %d not found in database records.\n", searchId);
    }
}

void checkStatus() 
{
    int searchId, i, found = 0;

    if (ticketCount == 0) 
    {
        printf("\nBooking storage database empty.\n");
        return;
    }

    printf("\nEnter Ticket ID to check status: ");
    scanf("%d", &searchId);

    for (i = 0; i < ticketCount; i++) 
    {
        if (bookingDatabase[i].ticketId == searchId) 
        {
            printf("\n--- Booking Record Details ---");
            printf("\nID Number: %d", bookingDatabase[i].ticketId);
            printf("\nPassenger: %s", bookingDatabase[i].passengerName);
            printf("\nRoute to : %s", bookingDatabase[i].destination);
            printf("\nFare Paid: %.2f", bookingDatabase[i].fare);
            printf("\nStatus   : %s\n", (bookingDatabase[i].isConfirmed == 1) ? "Confirmed" : "Cancelled");
            found = 1;
            break;
        }
    }

    if (!found) 
    {
        printf("\nTicket ID %d match not found.\n", searchId);
    }
}