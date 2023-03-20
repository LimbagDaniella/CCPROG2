#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char String10[11];
typedef char String15[16];
typedef char String20[21];
typedef char String30[31];

typedef struct
{
	int day;
	int month;
	int year;
}dateType;

typedef struct userTag
{
	int role;
	int uid;
	String10 pass;
	String30 address;
	int nContact;
	String20 name;
}userType;

typedef struct itemTag
{
    int productID;
    String20 name;
    String15 catg;
    String30 desc;
    int nQuantity;
    float uPrice;
    int sID;
}itemType;

typedef struct sellerTag
{
	int uid;
	int nItems;
	itemType itemList[20];
}sellerType;

typedef struct transactionTag
{
    dateType date;
    itemType items[5];
    int buyerID;
    int sellerID;
    int totalAmount;
}transactionType;

/****************************************
Description : 
@param :
@return :
*****************************************/
int searchUser(userType users[100], int index)
{
	int i = 0, found = 0;
	int key = users[index].uid;
    while(i < index && found == 0)
	{
		if (key == users[i].uid)
			found = 1;
		i++;
    }
    return found;
}

/****************************************
Description : 
@param :
@return :
*****************************************/
int checkUser(userType users[100], int kUID, String10 kPass, int num)
{
	int i = 0, found = 0, index;
    while(i < num && !found)
	{
	    if (kUID == users[i].uid)
	    {
	    	found = 1;
	    	index = i;
		}
		i++;
    }
    if(found)
    {
    	found = 0;
    	
    	if(strcmp(kPass, users[index].pass) != 0)
    	{
    		found = 1;
    	}
    	
		if(found)
		{
			printf("Error! Incorrect password.\n");
			return 0;
		}
		else
			return 1;
	}
	else
	{
		printf("Error! User not found.\n");
		return 0;
	}
}

/****************************************
Description : 
@param :
@return :
*****************************************/
int findIndex(userType users[100], int key, int num)
{
	int i = 0, found = 0;
    while(i < num && !found)
	{
		if (key == users[i].uid)
			found = 1;
		i++;
    }
    return i-1;
}


/****************************************
Description : 
@param :
@return : 
*****************************************/
void getString(char * str) 
{
  int i;
  char ch;
  
  i = 0;
  do 
  {
    scanf("%c", &ch);
    if (ch != '\n') 
{
      str[i] = ch;
      i++;
    }
  } while (ch != '\n');
  str[i] = '\0';
}

/****************************************
Description : 
@param :
@return : 
*****************************************/
void registerUser(userType *u)
{
	char cDump;
	
	do
	{
	printf("Are you a buyer or seller?\n");
	printf("[1] Buyer\n");
	printf("[2] Seller\n");
	scanf("%d%c", &u->role, &cDump);
	if(u->role != 1 && u->role != 2)
		{
			system("CLS");
			printf("Invalid input!\n");
		}
	}while(u->role != 1 && u->role != 2);
	
	printf("\nEnter your user ID: ");
	scanf("%d%c", &u->uid, &cDump);
	
	printf("Enter your password (up to 10 characters): ");
	getString(u->pass);
	
	printf("Enter your address: ");
	getString(u->address);
	
	printf("Enter your contact number: ");
	scanf("%d%c", &u->nContact, &cDump);
	
	printf("Enter your name: ");
	getString(u->name);
}

/****************************************
Description : 
@param :
@return : 
*****************************************/
void loginUser(int *cUID, String10 *cPass)
{	
	char cDump;
	
	printf("User ID: ");
	scanf("%d%c", &(*cUID), &cDump);
	printf("\n");
	
	printf("Password: ");
	getString(*cPass);
	printf("\n");
}

/****************************************
Description : 
@param :
@return : 
*****************************************/
int searchSeller(sellerType list[100], int key, int num)
{
	int i = 0, found = 0;
    while(i < num && found == 0)
	{
	    if (key == list[i].uid)
			found = 1;
		i++;
    }
    return i-1;
}

/****************************************
Description : 
@param :
@return : 
*****************************************/
void addItem(itemType *i)
{
	char cDump;
	
	printf("Product ID: ");
	scanf("%d%c", &i->productID, &cDump);
	
	printf("Product name: ");
	getString(i->name);
	
	printf("Category: ");
	getString(i->catg);
	
	printf("Description: ");
	getString(i->desc);
	
	printf("Quantity: ");
	scanf("%d%c", &i->nQuantity, &cDump);
	
	printf("Unit price: ");
	scanf("%f%c", &i->uPrice, &cDump);
	
	printf("Item details saved...\n");
	printf("Press ENTER to continue.\n");
	scanf("%c", &cDump);
}

void displayItems(itemType iList[20])
{
	int i;
	String10 header[5] = {"ProductID", "Item Name", "Category", "Unit Price", "Quantity"};
	printf("%-10s ", header[0]);
	printf("%20s ", header[1]);
	printf("%15s ", header[2]);
	printf("%30s ", header[3]);
	printf("%-2s", header[4]);
	printf("\n");
	for(i=0;i<=5;i++)
	{
		printf("%-10d ", iList[i].productID);
		printf("%20s ", iList[i].name);
		printf("%15s ", iList[i].catg);
		printf("%30s ", iList[i].desc);
		printf("%-2d", iList[i].nQuantity);
		printf("\n");
	}
}

void editItem(itemType *i)
{
	char cDump;
	
	printf("Product ID: ");
	scanf("%d%c", &i->productID, &cDump);
	
	printf("Product name: ");
	getString(i->name);
	
	printf("Category: ");
	getString(i->catg);
	
	printf("Description: ");
	getString(i->desc);
	
	printf("Quantity: ");
	scanf("%d%c", &i->nQuantity, &cDump);
	
	printf("Unit price: ");
	scanf("%f%c", &i->uPrice, &cDump);
	
	printf("Item details saved...\n");
	printf("Press ENTER to continue.\n");
	scanf("%c", &cDump);
}



/**
void registerUser(userType *u, int numUsers)
{
    printf("Enter user ID: ");
    scanf("%d", &u.userID);
    // checking userID duplicate

    // input user name
    printf("Enter user name: ");
    scanf("%s", name);

    // adding the user to array

    u[*numUsers].type.buyer = 'Y'; //y = buyer
    u[*numUsers].type.seller = 'N'; //n = seller
    u[*numUsers].userID = userID;
    strcpy(u[*numUsers].pass, "password");
    strcpy(u[*numUsers].address, "address");
    u[*numUsers].nContact = 1234567890;
    strcpy(users[*numUsers].name, name);
    (*numUsers)++;
    printf("User registered successfully\n");

}
**/

