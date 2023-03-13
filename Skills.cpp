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
	maxSkillPoints = 60;
}

//Displays skills and their current totals
void displayCategories()
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
	displayCategories();
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

void displayAwareness()
{
	cout << "0 : Concentration (WILL):\t\t" 
		<< awareness[0] << endl;
	cout << "1 : Conceal/Reveal Object (WILL):\t" 
		<< awareness[1] << endl;
	cout << "2 : Lip Reading (INT):\t\t\t"
		<< awareness[2] << endl;
	cout << "3 : Perception (INT):\t\t\t"
		<< awareness[3] << endl;
	cout << "4 : Tracking (INT):\t\t\t" 
		<< awareness[4] << endl;
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

int bodyMenu()
{
	//display body skills
	//edit body[]
	return 0;
}

int controlMenu()
{
	//display control skills
	//edit control[]
	return 0;
}

int educationMenu()
{
	//display education skills
	//edit education[]
	return 0;
}

int fightingMenu()
{
	//display fighting skills
	//edit fighting[]
	return 0;
}

int performanceMenu()
{
	//display performance skills
	//edit performance[]
	return 0;
}

int rangedWeaponMenu()
{
	//display ranged weapon skills
	//edit rangedWeapon[]
	return 0;
}

int socialMenu()
{
	//display social skills
	//edit social[]
	return 0;
}

int techniqueMenu()
{
	//display technique skills
	//edit technique[]
	return 0;
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
			in = awarenessMenu();
			break;
		case 1: //BODY
			in = bodyMenu();
			break;
		case 2: //CONTROL
			in = controlMenu();
			break;
		case 3: //EDUCATION
			in = educationMenu();
			break;
		case 4: //FIGHTING
			in = fightingMenu();
			break;
		case 5: //PERFORMANCE
			in = performanceMenu();
			break;
		case 6: //RANGED WEAPON
			in = rangedWeaponMenu();
			break;
		case 7: //SOCIAL
			in = socialMenu();
			break;
		case 8: //TECHNIQUE
			in = techniqueMenu();
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
}