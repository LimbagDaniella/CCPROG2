#include "mp.h"

int main()
{
	userType UserList[100];
	sellerType SellerList[100];
	
	int choice = 0, schoice = 0, nUsers = 0, found = 0, nSellers = 0, nBuyers = 0, nItems = 0;
	int index, valid;
	String10 cPass;
	int cUID = 0;
	char cDump;
	
	//Main menu
	while(choice != 1 || choice != 2)
	{
		system("CLS");
		printf("---Main Menu---\n");
		printf("[1] Register\n");
		printf("[2] Log-in");
		printf("\n");
		scanf("%d%c", &choice, &cDump);
		
		switch(choice)
		{
			//User registration
			case 1:
				system("CLS");
				printf("---Register user---\n");
				registerUser(&UserList[nUsers]);
				do
				{
					found = searchUser(UserList, nUsers);
					if(found)
					{
						system("CLS");
						printf("User ID already exists!\n");
						printf("\nEnter your user ID: ");
						scanf("%d%c", &UserList->uid, &cDump);
					}
				}while(found);
				if (UserList[nUsers].role == 1)
				{
					SellerList[nSellers].uid = UserList[nUsers].uid;
					nBuyers++;
				}
				else
				{
					SellerList[nSellers].uid = UserList[nUsers].uid;
					nSellers++;
				}
				nUsers++;
				break;
			
			//User login
			case 2:
				system("CLS");
				printf("---Log-in---\n");
				loginUser(&cUID, &cPass);
				valid = checkUser(UserList, cUID, cPass, nUsers);
				if(!valid)
				{
					printf("Press ENTER to return to main menu.\n");
					scanf("%c", &cDump);
					system("CLS");
					break;
				}
				else
				{
					index = findIndex(UserList, cUID, nUsers);
					system("CLS");
					
					switch (UserList[index].role)
					{
						//Buyer Menu
						/**
						case 1:
							break;
						**/
						//Sell Menu
						case 2:
							do
							{
							index = searchSeller(SellerList, cUID, nUsers);
							printf("---Sell Menu---\n");
							printf("[1] Add New Item\n");
							printf("[2] Edit Stock\n");
							printf("[3] Show My Products\n");
							printf("[4] Show My Low Stock Products\n");
							printf("[5] Exit\n");
							scanf("%d%c", &schoice, &cDump);
							
							switch (schoice)
							{
								case 1:
									if (SellerList[index].nItems < 20)
									{
									addItem(&SellerList[index].itemList[nItems]);
									}
									else
									{
										printf("Limit has been reached.\n");
										printf("Press ENTER to return to the Sell Menu.\n");
										scanf("%c", &cDump);
									}
									break;
									
								case 2:
									if (SellerList[index].nItems > 0)
									{
										displayItems(SellerList[index].itemList);
									}
									break;
									/**
								case 3:
									break;
								case 4:
									break;
								case 5:
									break;
								default:
									system("CLS");
									printf("Invalid Input! Please try again.");
									break;**/
							}
							break;
						}while(schoice != 5);
					}
				}
				break;
				
			default:
				system("CLS");
				printf("Invalid input! Please try again.\n");
				break;
		}
	}
	
	return 0;
}
