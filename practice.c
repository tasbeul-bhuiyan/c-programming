#include<stdio.h>          // Include standard input/output library for printf, scanf, etc.
#include<stdlib.h>         // Include standard library for general utilities
#include<string.h>         // Include string library for string manipulation functions

#define max_bookings 50    // Define maximum number of bookings allowed (constant)
#define name_size 100      // Define maximum size for names and passwords (constant)

// Global arrays to store booking information
char names[max_bookings][name_size];      // 2D array to store club names for each booking
char passwords[max_bookings][name_size];  // 2D array to store passwords for each booking
int days[max_bookings], slots[max_bookings], count = 0;  // Arrays for days, slots, and booking counter

// Predefined arrays for days and time slots
char day_length[7][10]={"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};  // Day names array
char time_slots[5][15]={"6-9 AM", "9-12 PM", "12-3 PM", "3-6 PM", "6-9 PM"};  // Time slot descriptions
int prices[5]={3000, 3000, 3000, 4000, 4500};  // Prices for each time slot (last two are more expensive)

// Function to save all bookings to a file
void save_club(){
FILE *fp = fopen("clubs.txt","wt");  // Open file in write text mode
if(fp == NULL){ return;}             // Return if file cannot be opened
for(int i = 0;i<count;i++) {         // Loop through all bookings
    fprintf(fp, "%s,%s,%d,%d\n", names[i], passwords[i], days[i], slots[i]);  // Write booking data in CSV format
}
fclose(fp);  // Close the file
}

// Function to load bookings from file
void load_club(){
FILE *fp = fopen("clubs.txt","rt");  // Open file in read text mode
if(fp==NULL){return;}                // Return if file doesn't exist or can't be opened
count = 0;                           // Reset booking counter
char name[name_size],pass[name_size],day_txt[10],slot_txt[10];  // Temporary buffers for reading data
int name_len = 0,pass_len = 0,day_len = 0,slot_len = 0,stage = 0,ch;  // Length counters, stage tracker, and character variable

name[0]=pass[0]=day_txt[0]=slot_txt[0]='\0';  // Initialize all buffers with null terminators

while((ch = fgetc(fp))!= EOF && count < max_bookings){  // Read file character by character until EOF or max bookings
    if (ch == ','){                  // If comma is found (field separator)
        if(stage == 0){              // If reading name field
            name[name_len] ='\0';    // Null terminate the name string
            stage = 1;               // Move to password field
        }
        else if(stage == 1){         // If reading password field
            pass[pass_len] ='\0';    // Null terminate the password string
            stage = 2;               // Move to day field
        }
        else if (stage == 2){        // If reading day field
            day_txt[day_len] ='\0';  // Null terminate the day string
            stage = 3;               // Move to slot field
        }
        }
    else if(ch == '\n'){             // If newline is found (record separator)
        slot_txt[slot_len]='\0';     // Null terminate the slot string
        int day_num = 0, slot_num = 0;  // Variables to store converted numbers

        for(int i = 0; day_txt[i]; i++){      // Convert day string to number
            if(day_txt[i] >= '0' && day_txt[i] <= '9'){  // If character is a digit
                day_num = day_num * 10 + (day_txt[i] - '0');  // Build the number
            }
        }
        for(int i = 0; slot_txt[i]; i++){     // Convert slot string to number
            if(slot_txt[i] >= '0' && slot_txt[i] <= '9'){  // If character is a digit
                    slot_num = slot_num * 10 + (slot_txt[i] - '0');  // Build the number
            }
        }
        if(day_num >= 1 && day_num <= 7 && slot_num >= 1 && slot_num <= 5 && name_len > 0 && pass_len > 0){  // Validate data
            strcpy(names[count],name);      // Copy name to global array
            strcpy(passwords[count],pass);  // Copy password to global array
            days[count] = day_num;          // Store day number
            slots[count++] = slot_num;      // Store slot number and increment counter
            }
            stage = 0;                      // Reset to name field for next record
            name_len = pass_len = day_len = slot_len = 0;  // Reset all length counters
            name[0] = pass[0] = day_txt[0] = slot_txt[0] = '\0';  // Reset all buffers
        }
        else {                              // If not comma or newline, it's data
            if(stage == 0 && name_len < name_size-1)     // If reading name and buffer not full
                {name[name_len++] = ch;}                  // Add character to name buffer
            else if (stage == 1 && pass_len < name_size-1)  // If reading password and buffer not full
                {pass[pass_len++] = ch;}                     // Add character to password buffer
            else if (stage == 2 && day_len < 9)         // If reading day and buffer not full
                {day_txt[day_len++] = ch;}               // Add character to day buffer
            else if (stage == 3 && slot_len < 9)        // If reading slot and buffer not full
                {slot_txt[slot_len++] = ch;}             // Add character to slot buffer
        }
}
fclose(fp);  // Close the file
}

// Function to get a valid number input within a range
int choose_number(int min, int max){
int num;        // Variable to store the input number
while(1){       // Infinite loop until valid input
  if(scanf("%d", &num) == 1 && num >= min && num <= max){  // If valid integer within range
     while (getchar() != '\n');  // Clear input buffer
    return num;                   // Return the valid number
   }
  printf("Invalid! Enter %d-%d: ", min, max);  // Show error message
    while (getchar() != '\n');                 // Clear input buffer
}
}

// Function to display a message and get string input
void display_message(char *buffer, const char *message){
printf("%s",message);                    // Display the message
fgets(buffer,name_size,stdin);           // Read string input
buffer[strcspn(buffer,"\n")] = '\0';     // Remove newline character from input
}

// Function to check if a specific slot is already booked
int slot_booked(int day, int slot) {
for(int i=0;i<count;i++){               // Loop through all bookings
    if(days[i] == day && slots[i] == slot){  // If day and slot match
      return 1;                         // Return 1 (true) - slot is booked
    }
}
return 0;                               // Return 0 (false) - slot is available

}

// Function to display available slots for a specific day
void available_slots(int day){
printf("\n%s slots:\n", day_length[day-1]);  // Print day name (array is 0-indexed, day is 1-indexed)
for(int i = 1; i <= 5; i++){                 // Loop through all 5 time slots
    printf("%d. %s - ", i, time_slots[i-1]); // Print slot number and time (array is 0-indexed)
    if (slot_booked(day, i)){printf("BOOKED\n");}  // If slot is booked, show "BOOKED"
    else{printf("Available (%d TK)\n", prices[i-1]);}  // If available, show price
    }
}

// Function to verify club name and password combination
int check_info(const char *club_name,const char *password){
for(int i=0;i< count; i++){             // Loop through all bookings
    if (strcmp(names[i], club_name) == 0 && strcmp(passwords[i], password) == 0){  // If both name and password match
        return 1;                       // Return 1 (true) - credentials are valid
    }
}
return 0;                               // Return 0 (false) - credentials not found
}

// Function to book new slots
void book_slots(){
char club_name[name_size], password[name_size];  // Buffers for club name and password
display_message(club_name, "Club name: ");       // Get club name from user
display_message(password, "Password: ");         // Get password from user
int remaining = max_bookings - count;            // Calculate remaining booking slots
printf("Available slots to book: %d\n", remaining);  // Display remaining slots
if (remaining == 0){                             // If no slots remaining
    printf("Booking limit reached!\n");          // Show error message
    return;                                      // Exit function
}
printf("How many slots to book (1-%d): ", remaining >10?10:remaining);  // Ask how many slots (max 10 or remaining)
int num_slots =choose_number(1,remaining>10?10:remaining);  // Get valid number of slots

int total_cost =0, booked_done =0;              // Initialize cost and booking counters
for(int i = 0;i < num_slots;i++) {              // Loop for each slot to book
if (count >= max_bookings){ break; }            // Break if booking limit reached

printf("\n--- Slot #%d ---\n", i+1);           // Display slot number being processed
printf("Days:\n");                              // Display days header
for (int j=1; j<=7;j++)                         // Loop through all days
    printf("%d. %s\n", j, day_length[j-1]);     // Display day number and name

    printf("Choose day (1-7): ");               // Ask for day selection
    int day =choose_number(1, 7);               // Get valid day number
    available_slots(day);                       // Show available slots for selected day

    printf("Choose slot (1-5): ");              // Ask for slot selection
    int slot =choose_number(1, 5);              // Get valid slot number
    if(slot_booked(day, slot)){                 // If slot is already booked
      printf("Sorry, slot already booked! Skipping...\n");  // Show error message
      continue;                                 // Skip to next iteration
    }

    strcpy(names[count],club_name);             // Store club name for this booking
    strcpy(passwords[count],password);          // Store password for this booking
    days[count]=day;                            // Store day for this booking
    slots[count++]=slot;                        // Store slot for this booking and increment counter

    int cost = prices[slot-1];                  // Get price for this slot (array is 0-indexed)
    total_cost += cost;                         // Add to total cost
    booked_done++;                              // Increment successful bookings counter
    printf("|..Booked: %s %s - %d TK..|\n", day_length[day-1], time_slots[slot-1], cost);  // Confirmation message
    printf("Remaining slots you can book: %d\n",max_bookings - count);  // Show remaining available slots
}

printf("\n=== SUMMARY ===\n");                 // Display booking summary header
printf("Club: %s\n", club_name);               // Show club name
printf("Booked: %d slots\n",booked_done);      // Show number of slots booked
printf("Total: %d TK\n", total_cost);          // Show total cost

if (booked_done>0){                             // If at least one slot was booked
    save_club();                                // Save data to file
}
}

// Function to display bookings for a specific club
void club_booked(){
char club_name[name_size],password[name_size];  // Buffers for credentials
display_message(club_name,"Club name: ");       // Get club name
display_message(password,"Password: ");         // Get password

if (!check_info(club_name, password)) {         // If credentials are invalid
    printf("...Invalid club name or password!...\n");  // Show error message
    return;                                     // Exit function
}
printf("\n=== YOUR BOOKINGS ===\n");           // Display bookings header
printf("%-12s %-15s %-10s\n", "Day", "Time", "Price");  // Display column headers with formatting
printf("--------------------------------------\n");       // Display separator line

int found = 0,total = 0;                        // Initialize counters
for(int i = 0; i<count; i++) {                  // Loop through all bookings
    if (strcmp(names[i], club_name)==0 && strcmp(passwords[i], password)==0) {  // If booking belongs to this club
       printf("%-12s %-15s %-10d TK\n", day_length[days[i]-1], time_slots[slots[i]-1], prices[slots[i]-1]);  // Display booking details
       total += prices[slots[i]-1];             // Add to total cost
       found++;                                 // Increment found counter
    }
}

if (found == 0){                                // If no bookings found
        printf("No bookings found.\n");         // Show message
}
    else{                                       // If bookings were found
        printf("Total bookings: %d, Total cost: %d TK\n", found,total);  // Show summary
}

}

// Function to cancel a booking
void cancel_booking(){
char club_name[name_size],password[name_size];  // Buffers for credentials
display_message(club_name,"Club name: ");       // Get club name
display_message(password,"Password: ");         // Get password

  if (!check_info(club_name, password)){        // If credentials are invalid
    printf("Invalid club name or password!\n"); // Show error message
    return;                                     // Exit function
    }

printf("Your bookings:\n");                     // Display bookings header
int club_bookings[max_bookings], booking_count =0;  // Array to store indices and counter

for(int i=0;i<count;i++) {                      // Loop through all bookings
    if(strcmp(names[i],club_name)==0 && strcmp(passwords[i],password)==0) {  // If booking belongs to this club
        printf("%d. %s %s\n", booking_count+1, day_length[days[i]-1],time_slots[slots[i]-1]);  // Display booking with selection number
        club_bookings[booking_count++] = i;     // Store booking index and increment counter
    }
}

if(booking_count == 0){                         // If no bookings found
    printf("No bookings to cancel.\n");         // Show message
    return;                                     // Exit function
}

printf("Select booking to cancel (1-%d): ",booking_count);  // Ask user to select booking to cancel
int choice = choose_number(1, booking_count)-1; // Get valid choice and convert to 0-based index
int index = club_bookings[choice];              // Get actual booking index from stored indices

printf("Cancelled: %s %s (Refund: %d TK)\n",day_length[days[index]-1],time_slots[slots[index]-1], prices[slots[index]-1]);  // Show cancellation confirmation
for (int i =index; i <count-1; i++) {          // Shift all bookings after cancelled one
    strcpy(names[i], names[i+1]);              // Move name
    strcpy(passwords[i], passwords[i+1]);      // Move password
    days[i] = days[i+1];                       // Move day
    slots[i] = slots[i+1];                     // Move slot
}
count--;                                        // Decrease total booking count
save_club();                                    // Save updated data to file
}

// Function to show all available slots for all days
void show_available_slots(){
printf("\n=== AVAILABLE SLOTS ===\n");         // Display header
for(int day = 1; day <= 7; day++){             // Loop through all 7 days
    available_slots(day);                       // Show available slots for each day
}
printf("\nTotal available slots: %d\n",max_bookings-count);  // Show total remaining slots
}

// Main function - program entry point
int main(){
load_club();                                    // Load existing bookings from file
int choice;                                     // Variable to store menu choice
while (choice != 5){                           // Loop until user chooses to exit (option 5)
    printf("\n=== FOOTBALL Turf Management ===\n");  // Display main menu header
    printf("1. Book Slots\n");                 // Menu option 1
    printf("2. Show My Bookings\n");           // Menu option 2
    printf("3. Cancel Booking\n");             // Menu option 3
    printf("4. Show Available Slots\n");       // Menu option 4
    printf("5. Exit\n");                       // Menu option 5
    printf("Choice (1-5): ");                  // Prompt for choice

    choice = choose_number(1, 5);              // Get valid menu choice

    switch(choice){                            // Execute based on user choice
        case 1:                                // If user chose option 1
            book_slots();                      // Call booking function
        break;                                 // Exit switch case
        case 2:                                // If user chose option 2
            club_booked();                     // Call show bookings function
        break;                                 // Exit switch case
        case 3:                                // If user chose option 3
            cancel_booking();                  // Call cancel booking function
        break;                                 // Exit switch case
        case 4:                                // If user chose option 4
            show_available_slots();            // Call show available slots function
        break;                                 // Exit switch case
        case 5:                                // If user chose option 5
            save_club();                       // Save data before exiting
        printf("Thank you for visiting!\n");   // Display goodbye message
        break;                                 // Exit switch case
        }
}

return 0;                                      // Return 0 to indicate successful program termination
}
