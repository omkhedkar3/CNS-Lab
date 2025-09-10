#include <stdio.h>

#include <math.h>

int main() {

    int data[10];

    int data_at_reciever[10];

    int c,c1,c2,c3,i;


    printf("Enter 4 bits of data one by one\n");

    scanf("%d", &data[0]);

    scanf("%d", &data[1]);

    scanf("%d", &data[2]);

    scanf("%d", &data[4]);

    //Calculation of even parity

    data[6] = data[0] ^ data[2] ^ data[4];

    data[5] = data[0] ^ data[1] ^ data[4];

    data[3] = data[0] ^ data[1] ^ data[2];


   printf("\nEnter received data bits one by one\n");

for (i = 0; i < 7; i++) {

    scanf("%d", &data_at_reciever[i]);

}



c1 = data_at_reciever[6] ^ data_at_reciever[4] ^ data_at_reciever[2] ^ data_at_reciever[0];

c2 = data_at_reciever[5] ^ data_at_reciever[4] ^ data_at_reciever[1] ^ data_at_reciever[0];

c3 = data_at_reciever[3] ^ data_at_reciever[2] ^ data_at_reciever[1] ^ data_at_reciever[0];

c = c3 * 4 + c2 * 2 + c1 ;



if(c == 0) {

    printf("No error while transmission of data\n");

}

else {

    printf("Error on position %d", c);    

    printf("\nData sent : ");

    for (i = 0; i < 7; i++) {

        printf("%d ", data[i]);

    }


    printf("\nData received : ");

    for (i = 0; i < 7; i++) {

        printf("%d ", data_at_reciever[i]);

    }


    printf("\nCorrect message is\n");


    //if errorneous bit is 0 we complement it else vice versa

    if(data_at_reciever[7-c] == 0) {

        data_at_reciever[7-c] = 1;

    }

    else {

        data_at_reciever[7-c] = 0;

    }

    for (i = 0; i < 7; i++) {

        printf("%d ",data_at_reciever[i]);

    }

}



return 0;




}


#include <stdio.h>

int main() {
    int data[11]; // Array to hold encoded data
    int datacheck[11]; // Array to hold received data for checking
    int c1, c2, c3, c4, c, i;

    // Input 7 bits of data
    printf("Enter 7 bits of data one by one (e.g., 1 0 1 1 0 1 0):\n");
    scanf("%d", &data[2]); // D1
    scanf("%d", &data[4]); // D2
    scanf("%d", &data[5]); // D3
    scanf("%d", &data[6]); // D4
    scanf("%d", &data[8]); // D5
    scanf("%d", &data[9]); // D6
    scanf("%d", &data[10]); // D7

    // Calculate parity bits
    data[0] = data[2] ^ data[4] ^ data[6] ^ data[8] ^ data[10]; // P1
    data[1] = data[2] ^ data[5] ^ data[6] ^ data[9] ^ data[10]; // P2
    data[3] = data[4] ^ data[5] ^ data[6] ^ data[10]; // P4
    data[7] = data[8] ^ data[9] ^ data[10]; // P8

    // Display encoded data
    printf("\nEncoded data is:\n");
    for (i = 0; i < 11; i++)
        printf("%d", data[i]);
    printf("\n");

    // Input received data
    printf("\nEnter received data bits one by one:\n");
    for (i = 0; i < 11; i++)
        scanf("%d", &datacheck[i]);

    // Compute parity check bits
    c1 = datacheck[0] ^ datacheck[2] ^ datacheck[4] ^ datacheck[6] ^ datacheck[8] ^ datacheck[10]; // P1 check
    c2 = datacheck[1] ^ datacheck[2] ^ datacheck[5] ^ datacheck[6] ^ datacheck[9] ^ datacheck[10]; // P2 check
    c3 = datacheck[3] ^ datacheck[4] ^ datacheck[5] ^ datacheck[6] ^ datacheck[10]; // P4 check
    c4 = datacheck[7] ^ datacheck[8] ^ datacheck[9] ^ datacheck[10]; // P8 check

    c = c4 * 8 + c3 * 4 + c2 * 2 + c1; // Error position

    if (c == 0) {
        printf("\nNo error in the transmission of data.\n");
    } else {
        printf("\nFound error at position %d\n", c);

        // Display received and encoded data
        printf("\nEncoded data: ");
        for (i = 0; i < 11; i++)
            printf("%d", data[i]);

        printf("\nReceived data: ");
        for (i = 0; i < 11; i++)
            printf("%d", datacheck[i]);

        // Correct the erroneous bit
        if (datacheck[11 - c] == 0)
            datacheck[11 - c] = 1;
        else
            datacheck[11 - c] = 0;

        // Display corrected data
        printf("\nCorrected message is: ");
        for (i = 0; i < 11; i++)
            printf("%d", datacheck[i]);
        printf("\n");
    }

    return 0;
}