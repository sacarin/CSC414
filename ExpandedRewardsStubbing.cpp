/* 
This file displays an implementation of the digital catalog located with the Employee Rewards Shop of the MadeUpMart store.
The program will help users sort through the various item types and choose from options available within the store. 
It will then return a list of the items obtained, the points spent, the points voided, and the money spent.
It is an expansion of the Stubbing Project from class CSC 414. 

@file ExpandedRewardsStubbing.cpp
@author Jackie Diep
@date 11 / 14 / 2020

*/

//Include to include text input and output
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

//Include namespace std to save time, but should not use in larger projects that it may cause
//    namespace issues with
using namespace std;

//Main begins here
int main()
{
    //Initialize variables to hold trackers
    double spentPoints = 0;
    int quantityPurchased = 0;

    //Initialize item arrays to hold number of item types and variety of items
    // 10 = current amount of item types
    // 3 = amount of each item type
    string inventoryNames[10][3];
    double inventoryCosts[10][3];
    
    //Initialize variables to handle money calculation
    double moneyCostCalc = 0;
    double moneyCost = 0;
    double pointOverlap = 0;

    //Set max quant and initialize purchased item arrays (Purchased item array sizes must be same as max quant)
    double maxQuant = 20;
    string itemsPurchased[20];
    double purchasedCosts[20];

    //Set starting point amount, every employee is allocated 300 annually at the moment
    // Expire at end of year and must all be spent at once, so will always be 300
    double initPoints = 300;

    //Set current dollar to point conversion
    // Currently set to $1.50 : 1 point
    double costConversion = 1.50;



    //Inventory Initializations
    // Changes to inventory should only happen here unless 
    // The amount of item types or amount of options for each option change
    
    // Coffee Maker Initializations
    inventoryNames[0][0] = "Mainstays 5 Cup Black Coffee Maker";
    inventoryCosts[0][0] = 9.88;

    inventoryNames[0][1] = "Hamilton Beach FlexBrew 2-Way Coffee Maker";
    inventoryCosts[0][1] = 99.00;

    inventoryNames[0][2] = "Keurig K-Duo Plus Coffee Maker";
    inventoryCosts[0][2] = 229.99;

    // Fan Initializations
    inventoryNames[1][0] = "Comfort Zone 9-inch 2-Speed Portable Box Fan";
    inventoryCosts[1][0] = 11.63;

    inventoryNames[1][1] = "Lasko 20-inch Win Tunnel 3-Speed Fan with Remote";
    inventoryCosts[1][1] = 43.81;

    inventoryNames[1][2] = "Fan-Tastic Vent Endless Breeze 12-Volt Fan";
    inventoryCosts[1][2] = 127.21;

    // Heater Initializations
    inventoryNames[2][0] = "Soleil Electric Personal Ceramic Mini Heater 250W Indoor";
    inventoryCosts[2][0] = 10.94;

    inventoryNames[2][1] = "Remington Radiant 1200W Electric Portable Heater";
    inventoryCosts[2][1] = 59.00;

    inventoryNames[2][2] = "Honeywell My EnergySmart Infrared Heater";
    inventoryCosts[2][2] = 166.86;

    // Mug Initializations
    inventoryNames[3][0] = "Ozark Trail Double-wall Vacuum-sealed Stainless Steel Tumbler";
    inventoryCosts[3][0] = 8.74;

    inventoryNames[3][1] = "Bubba Hero XL 30 Ounce Vacuum-Insulated Stainless Steel";
    inventoryCosts[3][1] = 20.73;

    inventoryNames[3][2] = "Cauldryn Coffee Smart Mug";
    inventoryCosts[3][2] = 89.95;

    // Rug Initializations
    inventoryNames[4][0] = "Mainstays Taza Nylon Rug, Multi-Color";
    inventoryCosts[4][0] = 4.88;

    inventoryNames[4][1] = "Ottomanson Ultimate Shaggy Moroccan Trellis Area Rug";
    inventoryCosts[4][1] = 17.32;

    inventoryNames[4][2] = "Safavieh Natura Carly Geometric Braided Area Rug";
    inventoryCosts[4][2] = 94.79;

    // Weighted Blanket Initializations
    inventoryNames[5][0] = "Rest Haven Weighted Blanket Cover";
    inventoryCosts[5][0] = 19.99;

    inventoryNames[5][1] = "Tranquility Temperature Balancing Weighted Blanket with Washable Cover";
    inventoryCosts[5][1] = 34.97;

    inventoryNames[5][2] = "SensorPEDIC Serenity Weighted Blanket with Removable Cover";
    inventoryCosts[5][2] = 94.62;

    // Camera Initializations
    inventoryNames[6][0] = "Polaroid 16MP Waterproof Instant Sharing Digital Camera";
    inventoryCosts[6][0] = 39.96;

    inventoryNames[6][1] = "GoPro HERO7 White Action Camera";
    inventoryCosts[6][1] = 119.00;

    inventoryNames[6][2] = "KODAK PIXPRO Bridge Digital Camera";
    inventoryCosts[6][2] = 149.00;

    // Telescope Initializations
    inventoryNames[7][0] = "Inkach 4K Super Telephoto Zoom Monocular Telescope";
    inventoryCosts[7][0] = 26.95;

    inventoryNames[7][1] = "Meade Instruments Infinity Altazimuth Refractor Telescope";
    inventoryCosts[7][1] = 53.00;

    inventoryNames[7][2] = "Celestron PowerSeeker Refractor Telescope with Skymap";
    inventoryCosts[7][2] = 186.33;

    // Blender Initializations
    inventoryNames[8][0] = "MAINSTAYS Personal Blender";
    inventoryCosts[8][0] = 9.92;
                   
    inventoryNames[8][1] = "Ninja Professional 1000-Watt Blender";
    inventoryCosts[8][1] = 84.00;
                   
    inventoryNames[8][2] = "Oster Versa Pro Series Blender with Food Processor Attachment";
    inventoryCosts[8][2] = 210.00;

    // Desk Initializations
    inventoryNames[8][0] = "Furinno Go Green Home Computer Desk";
    inventoryCosts[8][0] = 46.61;

    inventoryNames[8][1] = "South Shore Smart Basics Work Desk";
    inventoryCosts[8][1] = 135.27;

    inventoryNames[8][2] = "KTaxon Brown Computer PC Desk Home Office Writing Table";
    inventoryCosts[8][2] = 219.99;

    cout << "Initial Points: " << initPoints << endl;

    //Initialize int whileCheck to repeat and exit the menu
    int whileCheck = 1;

    //While loop using whileCheck
    while (whileCheck != 0)
    {

        //Initialize variables local to each while loop

        // Index to describe currently selected item type
        int itemTypeIndex;

        // Variable to hold option selected of each type
        int purchaseOption;

        // Variable to test for valid option selection of each type
        int optionCheck = 0;

        // Variable to determine whether or not the user wants to continue
        char continueCheck = NULL;

        //Variable to determine whether or not the switch is complete
        int switchBreak = 0;

        //Initialize option to select through the menu
        char option;

        //Prompt for input and list the item type menu options
        cout << "\nPlease select an item type listed below." << endl;
        cout << "-----------------------------------------" << endl;
        cout << "1. Coffee Makers\n2. Fans\n3. Heaters\n4. Mugs\n5. Rugs\n6. Weighted Blankets\n7. Cameras\n8. Telescopes\n9. Blenders\n10. Desks\n";
        cout << "Select '0' to exit the menu." << endl;

        //Prompt for option input
        cout << "\nOption: ";

        //Obtain option input
        cin >> option;

        //Switch statement using option to select through the menu
        switch (option)
        {

        while (switchBreak == 0)
        {
                //Exit case, break every loop
        case '0':
            whileCheck = 0;
            switchBreak = 1;
            optionCheck = 1;
            continueCheck = 'N';
            break;

            //Coffee maker options
        case '1':

            //Reset continue option
            continueCheck = NULL;

            //Set itemTypeIndex to the first row
            itemTypeIndex = 0;

            //Display Coffee Makers and Prices
            cout << "\n***Reward Store: Coffee Makers" << endl;
            cout << "\n1.\tBudget: " << inventoryNames[itemTypeIndex][0] << endl;
            cout << "\tCost: " << inventoryCosts[itemTypeIndex][0] << endl;

            cout << "\n2.\tMid-Ranget: " << inventoryNames[itemTypeIndex][1] << endl;
            cout << "\tCost: " << inventoryCosts[itemTypeIndex][1] << endl;

            cout << "\n3.\tLuxury: " << inventoryNames[itemTypeIndex][2] << endl;
            cout << "\tCost: " << inventoryCosts[itemTypeIndex][2] << endl;
            cout << "*******************************" << endl;

            break;

            //Fan options
        case '2':
            //Reset continue option
            continueCheck = NULL;

            //Set itemTypeIndex to the second row
            itemTypeIndex = 1;

            //Display Fan options and Prices
            cout << "\n***Reward Store: Fans" << endl;
            cout << "\n1.\tBudget: " << inventoryNames[itemTypeIndex][0] << endl;
            cout << "\n\nCost: " << inventoryCosts[itemTypeIndex][0] << endl;

            cout << "\n2.\tMid-Ranget: " << inventoryNames[itemTypeIndex][1] << endl;
            cout << "\nCost: " << inventoryCosts[itemTypeIndex][1] << endl;

            cout << "\n3.\tLuxury: " << inventoryNames[itemTypeIndex][2] << endl;
            cout << "\nCost: " << inventoryCosts[itemTypeIndex][2] << endl;
            cout << "*******************************" << endl;
            break;

            //Heater options
        case '3':
            //Reset continue option
            continueCheck = NULL;

            //Set itemTypeIndex to the third row
            itemTypeIndex = 2;

            //Display Heaters and Prices
            cout << "\n***Reward Store: Heaters" << endl;
            cout << "\n1.\tBudget: " << inventoryNames[itemTypeIndex][0] << endl;
            cout << "\nCost: " << inventoryCosts[itemTypeIndex][0] << endl;

            cout << "\n2.\tMid-Ranget: " << inventoryNames[itemTypeIndex][1] << endl;
            cout << "\nCost: " << inventoryCosts[itemTypeIndex][1] << endl;

            cout << "\n3.\tLuxury: " << inventoryNames[itemTypeIndex][2] << endl;
            cout << "\nCost: " << inventoryCosts[itemTypeIndex][2] << endl;
            cout << "*******************************" << endl;
            break;

            //Mug options
        case '4':
            //Reset continue option
            continueCheck = NULL;

            //Set itemTypeIndex to the fourth row
            itemTypeIndex = 3;

            //Display Mugs and Prices
            cout << "\n***Reward Store: Mugs" << endl;
            cout << "\n1.\tBudget: " << inventoryNames[itemTypeIndex][0] << endl;
            cout << "\nCost: " << inventoryCosts[itemTypeIndex][0] << endl;

            cout << "\n2.\tMid-Ranget: " << inventoryNames[itemTypeIndex][1] << endl;
            cout << "\nCost: " << inventoryCosts[itemTypeIndex][1] << endl;

            cout << "\n3.\tLuxury: " << inventoryNames[itemTypeIndex][2] << endl;
            cout << "\nCost: " << inventoryCosts[itemTypeIndex][2] << endl;
            cout << "*******************************" << endl;
            break;

            //Rug options
        case '5':
            //Reset continue option
            continueCheck = NULL;

            //Set itemTypeIndex to the fifth row
            itemTypeIndex = 4;

            //Display Rugs and Prices
            cout << "\n***Reward Store: Rugs" << endl;
            cout << "\n1.\tBudget: " << inventoryNames[itemTypeIndex][0] << endl;
            cout << "\nCost: " << inventoryCosts[itemTypeIndex][0] << endl;

            cout << "\n2.\tMid-Ranget: " << inventoryNames[itemTypeIndex][1] << endl;
            cout << "\nCost: " << inventoryCosts[itemTypeIndex][1] << endl;

            cout << "\n3.\tLuxury: " << inventoryNames[itemTypeIndex][2] << endl;
            cout << "\nCost: " << inventoryCosts[itemTypeIndex][2] << endl;
            cout << "*******************************" << endl;
            break;

            //Weighted blanket options
        case '6':
            //Reset continue option
            continueCheck = NULL;

            //Set itemTypeIndex to the sixth row
            itemTypeIndex = 5;

            //Display Weighted Blankets and Prices
            cout << "\n***Reward Store: Weighted Blankets" << endl;
            cout << "\n1.\tBudget: " << inventoryNames[itemTypeIndex][0] << endl;
            cout << "\nCost: " << inventoryCosts[itemTypeIndex][0] << endl;

            cout << "\n2.\tMid-Ranget: " << inventoryNames[itemTypeIndex][1] << endl;
            cout << "\nCost: " << inventoryCosts[itemTypeIndex][1] << endl;

            cout << "\n3.\tLuxury: " << inventoryNames[itemTypeIndex][2] << endl;
            cout << "\nCost: " << inventoryCosts[itemTypeIndex][2] << endl;
            cout << "*******************************" << endl;
            break;

            //Camera options
        case '7':
            //Reset continue option
            continueCheck = NULL;

            //Set itemTypeIndex to the seventh row
            itemTypeIndex = 6;

            //Display Cameras and Prices
            cout << "\n***Reward Store: Cameras" << endl;
            cout << "\n1.\tBudget: " << inventoryNames[itemTypeIndex][0] << endl;
            cout << "\nCost: " << inventoryCosts[itemTypeIndex][0] << endl;

            cout << "\n2.\tMid-Ranget: " << inventoryNames[itemTypeIndex][1] << endl;
            cout << "\nCost: " << inventoryCosts[itemTypeIndex][1] << endl;

            cout << "\n3.\tLuxury: " << inventoryNames[itemTypeIndex][2] << endl;
            cout << "\nCost: " << inventoryCosts[itemTypeIndex][2] << endl;
            cout << "*******************************" << endl;
            break;

            //Telescope options
        case '8':
            //Reset continue option
            continueCheck = NULL;

            //Set itemTypeIndex to the eighth row
            itemTypeIndex = 7;

            //Display Telescopes and Prices
            cout << "\n***Reward Store: Telescopes" << endl;
            cout << "\n1.\tBudget: " << inventoryNames[itemTypeIndex][0] << endl;
            cout << "\nCost: " << inventoryCosts[itemTypeIndex][0] << endl;

            cout << "\n2.\tMid-Ranget: " << inventoryNames[itemTypeIndex][1] << endl;
            cout << "\nCost: " << inventoryCosts[itemTypeIndex][1] << endl;

            cout << "\n3.\tLuxury: " << inventoryNames[itemTypeIndex][2] << endl;
            cout << "\nCost: " << inventoryCosts[itemTypeIndex][2] << endl;
            cout << "*******************************" << endl;
            break;

            //Blender options
        case '9':
            //Reset continue option
            continueCheck = NULL;

            //Set itemTypeIndex to the ninth row
            itemTypeIndex = 8;

            //Display Blenders and Prices
            cout << "\n***Reward Store: Blenders" << endl;
            cout << "\n1.\tBudget: " << inventoryNames[itemTypeIndex][0] << endl;
            cout << "\nCost: " << inventoryCosts[itemTypeIndex][0] << endl;

            cout << "\n2.\tMid-Ranget: " << inventoryNames[itemTypeIndex][1] << endl;
            cout << "\nCost: " << inventoryCosts[itemTypeIndex][1] << endl;

            cout << "\n3.\tLuxury: " << inventoryNames[itemTypeIndex][2] << endl;
            cout << "\nCost: " << inventoryCosts[itemTypeIndex][2] << endl;
            cout << "*******************************" << endl;
            break;

            //Desk options
        case '10':
            //Reset continue option
            continueCheck = NULL;

            //Set itemTypeIndex to the tenth row
            itemTypeIndex = 9;

            //Display Desks and Prices
            cout << "\n***Reward Store: Desks" << endl;
            cout << "\n1.\tBudget: " << inventoryNames[itemTypeIndex][0] << endl;
            cout << "\nCost: " << inventoryCosts[itemTypeIndex][0] << endl;

            cout << "\n2.\tMid-Ranget: " << inventoryNames[itemTypeIndex][1] << endl;
            cout << "\nCost: " << inventoryCosts[itemTypeIndex][1] << endl;

            cout << "\n3.\tLuxury: " << inventoryNames[itemTypeIndex][2] << endl;
            cout << "\nCost: " << inventoryCosts[itemTypeIndex][2] << endl;
            cout << "*******************************" << endl;
            break;

            //Entry for invalid input
        default:

            //Reset continue option
            continueCheck = NULL;
            switchBreak = 2;

            //Output Invalid Input
            cout << "\nInvalid item type menu entry. \nPlease try again." << endl;
            }

        }

        //Process what item type was selected and prompt for input
        if (switchBreak != 2)
        {
            while (optionCheck == 0)
            {

                //Display remaining points and prompt for a choice
                cout << "Points remaining: " << 300 - spentPoints << endl;
                cout << "Which would you like? (1-3)" << endl;
                cout << "4 to exit to menu" << endl;
                cout << "\nOption: ";
                cin >> purchaseOption;

                //If an invalid option is input
                if (purchaseOption <= 0 || purchaseOption >= 5)
                {
                    cout << "\nInvalid Option\n" << endl;
                }

                //If exit option is chosen
                else if (purchaseOption == 4)
                {
                    cout << "\nExiting to menu" << endl;
                    cout << "Points remaining: " << 300 - spentPoints << endl << endl;
                    optionCheck = 1;
                }

                //If the item costs more than possible
                else if ((spentPoints + inventoryCosts[itemTypeIndex][purchaseOption - 1]) > 350)
                {
                    cout << "\nItem cannot be afforded\n" << endl;
                }

                //If money must be used to supplement purchase
                else if ((spentPoints + inventoryCosts[itemTypeIndex][purchaseOption - 1]) > initPoints)
                {

                    //Calculate the amount of money to be spent and record the amount of points over the limit
                    pointOverlap = (spentPoints + inventoryCosts[itemTypeIndex][purchaseOption - 1] - initPoints);
                    moneyCostCalc = pointOverlap * costConversion;
                    moneyCost = moneyCostCalc + (moneyCostCalc * .07);

                    //Display the item information of the purchase
                    itemsPurchased[quantityPurchased] = inventoryNames[itemTypeIndex][purchaseOption - 1];
                    cout << "\nPurchased item name: " << itemsPurchased[quantityPurchased] << endl;
                    purchasedCosts[quantityPurchased] = inventoryCosts[itemTypeIndex][purchaseOption - 1];
                    cout << "Purchased item cost: " << purchasedCosts[quantityPurchased] << endl;

                    //Increment the quantity and set the amount of points spent to 300, all of them
                    quantityPurchased++;
                    spentPoints = 300;
                    cout << "\nMaximum number of points spent\n" << endl;

                    //Break all loops
                    whileCheck = 0;
                    continueCheck = 'N';
                    optionCheck = 1;
                }

                //If points are enough to cover purchase
                else
                {
                    //Display the item information of the purchase
                    itemsPurchased[quantityPurchased] = inventoryNames[itemTypeIndex][purchaseOption - 1];
                    cout << "\nPurchased item name: " << itemsPurchased[quantityPurchased] << endl;
                    purchasedCosts[quantityPurchased] = inventoryCosts[itemTypeIndex][purchaseOption - 1];
                    cout << "Purchased item cost: " << purchasedCosts[quantityPurchased] << endl;

                    //Increment the quantity and calculate the amount of points spent so far
                    quantityPurchased++;
                    spentPoints = spentPoints + inventoryCosts[itemTypeIndex][purchaseOption - 1];

                    //Check if the maximum quantity of items has been reached and break all loops if so
                    if (quantityPurchased >= maxQuant)
                    {
                        cout << "\nMaximum number of items purchased\n" << endl;
                        whileCheck = 0;
                        continueCheck = 'N';
                    }

                    //Break the current while loop and display the amount of points remaining
                    optionCheck = 1;
                    cout << "\nPoints remaining: " << 300 - spentPoints << endl;
                }
            }

            //While loop to check if the user would like to continue shopping
            while (continueCheck == NULL)
            {

                //Prompt for input and display options
                cout << "\nContinue shopping? (Y or N)" << endl;
                cout << "Continue: ";
                cin >> continueCheck;
                continueCheck = toupper(continueCheck);

                //If they would like to continue, do nothing
                if (continueCheck == 'Y')
                {
                }

                //If they would like to stop, break all loops
                else if (continueCheck == 'N')
                {
                    whileCheck = 0;
                }

                //If the option is invalid, reset input
                else
                {
                    cout << "\nNot a valid option" << endl;
                    continueCheck = NULL;
                }
            }
        }
        }



    //If items were purchased
    if (quantityPurchased > 0)
    {
        //Display the items purchased and their costs
        cout << "\n*************************************************************************" << endl;
        cout << "Number of Items Purchased: " << quantityPurchased << endl;
        cout << "Items Obtained:\n" << endl;
        for (int i = 0; i < quantityPurchased; i++)
        {
            cout << "\n" << itemsPurchased[i] << endl;
            cout << "Point Cost: " << purchasedCosts[i] << endl;
        }
        cout << "\n*************************************************************************" << endl;

        //Display the amount of points spent, points voided, and money spent
        cout << "\nPoints spent: " << spentPoints << endl;
        cout << "Points voided: " << initPoints - spentPoints << endl;
        cout << "Points over the limit: " << pointOverlap << endl;
        cout << fixed << setprecision(2) << "Money spent: $" << moneyCost << endl;

        //Thank the employee for using the store and give further instructions
        cout << "\nThank you for shopping at MadeUpMart's Employee Rewards Store." << endl;
        cout << "Please bring this ticket to the front desk. The current attendant shall retrieve your items for you." << endl;
    }

    //Say farewell and close the program
    cout << "\nHave a nice day!" << endl;
}