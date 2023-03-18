#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
using namespace std;

//current total of Skill Points
int skillPoints;
//maximum number of skill points
int maxSkillPoints;

int awareness[5];
/*
AWARENESS SKILLS
	0 - **Concentration (WILL)
	1 - Conceal/Reveal Object (INT)
	2 - Lip Reading (INT)
	3 - **Perception (INT)
	4 - Tracking (INT)
*/

int body[6];
/*
BODY SKILLS
	0 - **Athletics (DEX)
	1 - Contortionist (DEX)
	2 - Dance (DEX)
	3 - Endurance (WILL)
	4 - Reist Torture/Drugs (WILL)
	5 - **Stealth (DEX)
*/

int control[4];
/*
CONTROL SKILLS
	0 - Drive Land Vehicle (REF)
	1 - __Pilot Air Vehicle (x2) (REF)
	2 - Pilot Sea Vehicle (REF)
	3 - Riding (REF)
*/

int education[21];
/*
EDUCATION SKILLS
	0 - Accounting (INT)
	1 - Animal Handling (INT)
	2 - Bureaucracy (INT)
	3 - Business (INT)
	4 - Composition (INT)
	5 - Criminology (INT)
	6 - Cryptography (INT)
	7 - Deduction (INT)
	8 - **Education (INT)
	9 - Gamble (INT)
       10 - **Language (Streetslang) (INT)
       11 - Language (Misc 1) (INT)
       12 - Language (Misc 2) (INT)
       13 - Library Search (INT)
       14 - **Local Expert (Your Home) (INT)
       15 - Local Expert (Misc 1) (INT)
       16 - Local Expert (Misc 2) (INT)
       17 - Science (Misc 1) (INT)
       18 - Science (MIsc 2) (INT)
       19 - Tactics (INT)
       20 - Wilderness Survival (INT)
*/

int fighting[4];
/*
FIGHTING SKILLS
	0 - **Brawling (DEX)
	1 - **Evasion (DEX)
	2 - __Martial Arts (x2) (DEX)
	3 - Melee Weapon (DEX)
*/

int performance[3];
/*
PERFORMANCE SKILLS
	0 - Acting (COOL)
	1 - Play Instrument (Misc 1) (TECH)
	2 - Play Instrument (Misc 2) (TECH)
*/

int rangedWeapon[5];
/*
RANGED WEAPON SKILLS
	0 - Archery (REF)
	1 - __Autofire (x2) (REF)
	2 - Handgun (REF)
	3 - __Heavy Weapons (x2) (REF)
	4 - Shoulder Arms (REF)
*/

int social[9];
/*
SOCIAL SKILLS
	0 - Bribery (COOL)
	1 - **Conversation (EMP)
	2 - **Human Perception (EMP)
	3 - Interrogation (COOL)
	4 - **Persuasion (COOL)
	5 - Personal Grooming (COOL)
	6 - Streetwise (COOL)
	7 - Trading (COOL)
	8 - Wardrobe & Style (COOL)
*/

int technique[15];
/*
TECHNIQUE SKILLS
	0 - Air Vehicle Tech (TECH)
	1 - Basic Tech (TECH)
	2 - Cybertech (TECH)
	3 - __Demolitions (x2) (TECH)
	4 - __Electronics/Security Tech (x2) (TECH)
	5 - **First Aid (TECH)
	6 - Forgery (TECH)
	7 - Land Vehicle Tech (TECH)
	8 - Paint/Draw/Sculpt (TECH)
	9 - __Paramedic (x2) (TECH)
       10 - Photography/Film (TECH)
       11 - Pick Lock (TECH)
       12 - Pick Pocket (TECH)
       13 - Sea Vehicle Tech (TECH)
       14 - Weaponstech (TECH)
*/

//Set required skills to 2
//Initialize skill points (default 60)
void initializeSkills()
{
	//Required Awareness Skills
	awareness[0] = 2;	//Concentration (WILL)
	awareness[3] = 2;	//Perception (INT)

	//Required Body Skills
	body[0] = 2;		//Athletics (DEX)
	body[5] = 2;		//Stealth (DEX)

	//Required Education Skills
	education[8] = 2;	//Education (INT)
	education[10] = 2;	//Language (Streetslang) (INT)
	education[14] = 2;	//Local Expert (Your Home) (INT)

	//Required Fighting Skills
	fighting[0] = 2;	//Brawling (DEX)
	fighting[1] = 2;	//Evasion (DEX)

	//Required Social Skills
	social[1] = 2;		//Conversation (EMP)
	social[2] = 2;		//Human Perception (EMP)
	social[4] = 2;		//Persuasion (COOL)

	//Required Technique Skills
	technique[5] = 2;	//First Aid (TECH)

	skillPoints = 60;
	maxSkillPoints = 86;
}

//Displays skills and their current totals
void displayCategoriesList()
{
	cout << "0 : AWARENESS" << endl;
	cout << "1 : BODY" << endl;
	cout << "2 : CONTROL" << endl;
	cout << "3 : EDUCATION" << endl;
	cout << "4 : FIGHTING" << endl;
	cout << "5 : PERFORMANCE" << endl;
	cout << "6 : RANGED WEAPON" << endl;
	cout << "7 : SOCIAL" << endl;
	cout << "8 : TECHNIQUE" << endl;
}

//Prompt for category
int promptCategory()
{
	int in;
	displayCategoriesList();
	cout << "Category to edit (-1 to quit): ";
	cin >> in;
	return in;
}

//prompt for skill and return int input
int promptSkill()
{
	int in;
	cout << "SKILL (-1 to go back): ";
	cin >> in;
	return in;
}

/*
	METHODS TO DISPLAY THE SKILLS IN A GIVEN CATEGORY
*/

//Display the skills in the awareness category
void displayAwareness()
{
	cout << "0 : *Concentration (WILL):\t\t" 
		<< awareness[0] << endl;
	cout << "1 : Conceal/Reveal Object (WILL):\t" 
		<< awareness[1] << endl;
	cout << "2 : Lip Reading (INT):\t\t\t"
		<< awareness[2] << endl;
	cout << "3 : *Perception (INT):\t\t\t"
		<< awareness[3] << endl;
	cout << "4 : Tracking (INT):\t\t\t" 
		<< awareness[4] << endl;
}

//Display the skills in the body category
void displayBody()
{
	cout << "0 : *Athletics (DEX):\t\t\t" 
		<< body[0] << endl;
	cout << "1 : Contortionist (DEX):\t\t" 
		<< body[1] << endl;
	cout << "2 : Dance (DEX):\t\t\t"
		<< body[2] << endl;
	cout << "3 : Endurance (WILL):\t\t\t"
		<< body[3] << endl;
	cout << "4 : Resist Torture/Drugs (WILL):\t" 
		<< body[4] << endl;
	cout << "5 : *Stealth (DEX):\t\t\t" 
		<< body[5] << endl;
}

//Display the skills in the control category
void displayControl()
{
	cout << "0 : Drive Land Vehicle (REF):\t\t" 
		<< control[0] << endl;
	cout << "1 : Pilot Air Vehicle (x2) (REF):\t" 
		<< control[1] << endl;
	cout << "2 : Pilot Sea Vehicle (REF):\t\t"
		<< control[2] << endl;
	cout << "3 : Riding (REF):\t\t\t"
		<< control[3] << endl;
}

//Display the skills in the education category
void displayEducation()
{
	cout << "0 : Accounting (INT):\t\t\t" 
		<< education[0] << endl;
	cout << "1 : Animal Handling (INT):\t\t" 
		<< education[1] << endl;
	cout << "2 : Bureaucracy (INT):\t\t\t"
		<< education[2] << endl;
	cout << "3 : Business (INT):\t\t\t"
		<< education[3] << endl;
	cout << "4 : Composition (INT):\t\t\t"
		<< education[4] << endl;
	cout << "5 : Criminology (INT):\t\t\t"
		<< education[5] << endl;
	cout << "6 : Cryptography (INT):\t\t\t"
		<< education[6] << endl;
	cout << "7 : Deduction (INT):\t\t\t"
		<< education[7] << endl;
	cout << "8 : *Education (INT):\t\t\t"
		<< education[8] << endl;
	cout << "9 : Gamble (INT):\t\t\t"
		<< education[9] << endl;
	cout << "10: *Language (Streetslang) (INT):\t"
		<< education[10] << endl;
	cout << "11: Language (Misc 1) (INT):\t\t"
		<< education[11] << endl;
	cout << "12: Language (Misc 2) (INT):\t\t"
		<< education[12] << endl;
	cout << "13: Library Search (INT):\t\t"
		<< education[13] << endl;
	cout << "14: *Local Expert (Your Home) (INT):\t"
		<< education[14] << endl;
	cout << "15: Local Expert (Misc 1) (INT):\t"
		<< education[15] << endl;
	cout << "16: Local Expert (Misc 2) (INT):\t"
		<< education[16] << endl;
	cout << "17: Science (Misc 1) (INT):\t\t"
		<< education[17] << endl;
	cout << "18: Science (Misc 2) (INT):\t\t"
		<< education[18] << endl;
	cout << "19: Tactics (INT):\t\t\t"
		<< education[19] << endl;
	cout << "20: Wilderness Survival (INT):\t\t"
		<< education[20] << endl;
}

//Display the skills in the fighting category
void displayFighting()
{
	cout << "0 : *Brawling (DEX):\t\t" 
		<< fighting[0] << endl;
	cout << "1 : *Evasion (DEX):\t\t" 
		<< fighting[1] << endl;
	cout << "2 : Martial Arts (x2) (DEX):\t"
		<< fighting[2] << endl;
	cout << "3 : Melee Weapon (DEX):\t\t"
		<< fighting[3] << endl;
}

//Display the skills in the performance category
void displayPerformance()
{
	cout << "0 : Acting (COOL):\t\t\t" 
		<< performance[0] << endl;
	cout << "1 : Play Instrument (Misc 1) (TECH):\t" 
		<< performance[1] << endl;
	cout << "2 : Play Instrument (Misc 2) (TECH):\t" 
		<< performance[2] << endl;
}

//Display the skills in the ranged weapon category
void displayRangedWeapon()
{
	cout << "0 : Archery (REF):\t\t" 
		<< rangedWeapon[0] << endl;
	cout << "1 : Autofire (x2) (REF):\t" 
		<< rangedWeapon[1] << endl;
	cout << "2 : Handgun (REF):\t\t" 
		<< rangedWeapon[2] << endl;
	cout << "3 : Heavy Weapons (x2) (REF):\t" 
		<< rangedWeapon[3] << endl;
	cout << "4 : Shoulder Arms (REF):\t" 
		<< rangedWeapon[4] << endl;
}

//Display the skills in the social category
void displaySocial()
{
	cout << "0 : Bribery (COOL):\t\t" 
		<< social[0] << endl;
	cout << "1 : *Conversation (EMP):\t" 
		<< social[1] << endl;
	cout << "2 : *Human Perception (EMP):\t" 
		<< social[2] << endl;
	cout << "3 : Interrogation (COOL):\t" 
		<< social[3] << endl;
	cout << "4 : *Persuasion (COOL):\t\t" 
		<< social[4] << endl;
	cout << "5 : Personal Grooming (COOL):\t" 
		<< social[5] << endl;
	cout << "6 : Streetwise (COOL):\t\t" 
		<< social[6] << endl;
	cout << "7 : Trading (COOL):\t\t" 
		<< social[7] << endl;
	cout << "8 : Wardrobe & Style (COOL):\t" 
		<< social[8] << endl;
}

//Display the skills in the technique category
void displayTechnique()
{
	cout << "0 : Air Vehicle Tech (TECH):\t\t\t" 
		<< technique[0] << endl;
	cout << "1 : Basic Tech (TECH):\t\t\t\t" 
		<< technique[1] << endl;
	cout << "2 : Cybertech (TECH):\t\t\t\t" 
		<< technique[2] << endl;
	cout << "3 : Demolitions (x2) (TECH):\t\t\t" 
		<< technique[3] << endl;
	cout << "4 : Electronics/Security Tech (x2) (TECH):\t" 
		<< technique[4] << endl;
	cout << "5 : *First Aid (TECH):\t\t\t\t" 
		<< technique[5] << endl;
	cout << "6 : Forgery (TECH):\t\t\t\t" 
		<< technique[6] << endl;
	cout << "7 : Land Vehicle Tech (TECH):\t\t\t" 
		<< technique[7] << endl;
	cout << "8 : Paint/Draw/Sculpt (TECH):\t\t\t" 
		<< technique[8] << endl;
	cout << "9 : Paramedic (x2) (TECH):\t\t\t" 
		<< technique[9] << endl;
	cout << "10: Photography/Film (TECH):\t\t\t" 
		<< technique[10] << endl;
	cout << "11: Pick Lock (TECH):\t\t\t\t" 
		<< technique[11] << endl;
	cout << "12: Pick Pocket (TECH):\t\t\t\t" 
		<< technique[12] << endl;
	cout << "13: Sea Vehicle Tech (TECH):\t\t\t" 
		<< technique[13] << endl;
	cout << "14: Weaponstech (TECH):\t\t\t\t" 
		<< technique[14] << endl;
}

//Display all categories and skills
void displayAll()
{
	cout << "\t -----\tAWARENESS\t-----\n";
	displayAwareness();
	cout << endl << endl;

	cout << "\t -----\tBODY\t\t-----\n";
	displayBody();
	cout << endl << endl;

	cout << "\t -----\tCONTROL\t-----\n";
	displayControl();
	cout << endl << endl;

	cout << "\t -----\tEDUCATION\t-----\n";
	displayEducation();
	cout << endl << endl;

	cout << "\t -----\tFIGHTING\t-----\n";
	displayFighting();
	cout << endl << endl;

	cout << "\t -----\tPERFORMANCE\t-----\n";
	displayPerformance();
	cout << endl << endl;

	cout << "\t -----\tRANGED WEAPON\t-----\n";
	displayRangedWeapon();
	cout << endl << endl;

	cout << "\t -----\tSOCIAL\t-----\n";
	displaySocial();
	cout << endl << endl;

	cout << "\t -----\tTECHNIQUE\t-----\n";
	displayTechnique();
	cout << endl << endl;

	cout << "Skill Points Used:\t" << maxSkillPoints-skillPoints << "/" << maxSkillPoints
		<< endl << endl;
}

//Call the relevant function to display a given category
void displayCategory(int category)
{
	switch (category)
	{
	case 0:
		displayAwareness();
		break;
	case 1:
		displayBody();
		break;
	case 2:
		displayControl();
		break;
	case 3:
		displayEducation();
		break;
	case 4:
		displayFighting();
		break;
	case 5:
		displayPerformance();
		break;
	case 6:
		displayRangedWeapon();
		break;
	case 7:
		displaySocial();
		break;
	case 8:
		displayTechnique();
		break;
	}
}

//returns true if a given skill in a given category is required (min 2)
bool isRequiredSkill(int category, int skill)
{
	switch (category)
		{
		case 0: //AWARENESS
			return (skill == 0 || skill == 3);
		case 1: //BODY
			return (skill == 0  || skill == 5);
		case 2: //CONTROL
			return false;
		case 3: //EDUCATION
			return (skill == 8 || skill == 10 || skill == 14);
		case 4: //FIGHTING
			return (skill == 0 || skill == 1);
		case 5: //PERFORMANCE
			return false;
		case 6: //RANGED WEAPON
			return false;
		case 7: //SOCIAL
			return (skill == 1 || skill == 2 || skill == 4);
		case 8: //TECHNIQUE
			return (skill == 5);
		}
	return false;
}

//Display the menu for a category, given the category and its skill array
int categoryMenu(int skills[], int category)
{
	int input, rank;

	while(input != -1)
	{
		//display category skills
		displayCategory(category);

		//prompt for skill to edit
		input = promptSkill();
		if (input < -1 || input >= sizeof(skills)/sizeof(skills[0])) //OOB
		{
			cout << "input: " << input << endl << "sizeof(awareness): " << sizeof(skills) << endl;
			cout << "INVALID INPUT" << endl;
		}
		else
		{
			//prompt for rank to set skill to
			cout << "Set Skill #" << input << " to: ";
			cin >> rank;

			//set floor to 0 (or 2 if required)
			if (isRequiredSkill(0, input))
			{
				rank = max(2, rank);
			}
			else
			{
				rank = max(0, rank);
			}

			//rank is the increase or decrease from current skill rank
			rank = rank-skills[input];
			//update skill points
			skillPoints -= rank;
			//set skill
			skills[input] += rank;
		}
	}
	return input;
}

//functional but not used currently --holding onto it just in case
int awarenessMenu()
{
	//edit awareness[]
	int input, rank;
	while(input != -1)
	{
		//display awareness skills
		displayAwareness();
		
		//prompt for skill to edit
		input = promptSkill();
		if (input < -1 || input >= end(awareness)-begin(awareness)) //OOB
		{
			cout << "input: " << input << endl << "sizeof(awareness): " << sizeof(awareness) << endl;
			cout << "INVALID INPUT" << endl;
		}
		else
		{
			//prompt for rank to set skill to
			cout << "Set awareness Skill #" << input << " to: ";
			cin >> rank;

			//set floor to 0 (or 2 if required)
			if (isRequiredSkill(0, input))
			{
				rank = max(2, rank);
			}
			else
			{
				rank = max(0, rank);
			}

			//rank is the increase or decrease from current skill rank
			rank = rank-awareness[input];
			//update skill points
			skillPoints -= rank;
			//set skill
			awareness[input] += rank;
		}
	}
	return input;
}

//determine which array to modify based on input
void categoryMenu(int input)
{
	int in = input;
	while(in != -1)
	{
		switch (in)
		{
		case 0: //AWARENESS
			in = categoryMenu(awareness, in);
			break;
		case 1: //BODY
			in = categoryMenu(body, in);
			break;
		case 2: //CONTROL
			in = categoryMenu(control, in);
			break;
		case 3: //EDUCATION
			in = categoryMenu(education, in);
			break;
		case 4: //FIGHTING
			in = categoryMenu(fighting, in);
			break;
		case 5: //PERFORMANCE
			in = categoryMenu(performance, in);
			break;
		case 6: //RANGED WEAPON
			in = categoryMenu(rangedWeapon, in);
			break;
		case 7: //SOCIAL
			in = categoryMenu(social, in);
			break;
		case 8: //TECHNIQUE
			in = categoryMenu(technique, in);
			break;
		}
	}
}

int main()
{
	//initialize skill points and totals
	initializeSkills();

	//prompt on repeat
	int input;
	while(input != -1)
	{
		input = promptCategory();
		categoryMenu(input);
	}

	displayAll();
}