//Player's starting role
var myRole;

//Maximum number of stat points
var maxStatPoints = 62;

//Stat points remaining after initialization of stats at 2
var remStatPoints = maxStatPoints-20;

//Player's statistics
const stats = new Map();
stats.set('INT', 2);
stats.set('REF', 2);
stats.set('DEX', 2);
stats.set('TECH', 2);
stats.set('COOL', 2);
stats.set('WILL', 2);
stats.set('LUCK', 2);
stats.set('MOVE', 2);
stats.set('BODY', 2);
stats.set('EMP', 2);

//Map of skills (names, rank)
const skills = new Map();

//initialize required skills
skills.set('Concentration (WILL)', 2);
skills.set('Perception (INT)', 2);
skills.set('Athletics (DEX)', 2);
skills.set('Stealth (DEX)', 2);
skills.set('Education (INT)', 2);
skills.set('Streetslang', 2);
skills.set('Your Home', 2);
skills.set('Brawling (DEX)', 2);
skills.set('Evasion (DEX)', 2);
skills.set('Convesation (EMP)', 2);
skills.set('Human Perception (EMP)', 2);
skills.set('Persuasion (COOL)', 2);
skills.set('First Aid (TECH)', 2);

/*
	STEP 1: SELECT A ROLE
*/

//Select a role
function selectRole(role)
{
	var k = document.getElementById("roleButton");
	k.innerText = role;
	myRole = role;
}

/*
	STEP 3: BUY YOUR STATS
*/

//increase the rank of a stat by 1
//	input - string statName
function incrementStat(statName) 
{
	var rank = stats.get(statName);
	if (rank == 8)
	{
		console.log("STATS cannot be higher than 8");
		return;
	}

	stats.set(statName, rank+1);
}

//decrease the rank of a stat by 1
//	input - string statName
function decrementStat(statName) 
{
	var rank = stats.get(statName);
	if (rank == 2)
	{
		console.log("STATS cannot be lower than 2");
		return;
	}

	stats.set(statName, rank-1);
}

/*
	STEP 5: SET YOUR SKILLS
*/

//Increase a skill's rank by 1
//	input - string skillName
function incrementSkill(skillName)
{
	//get skill rank
	var rank = skills.get(skillName);

	//if incrementing past ceiling
	if (rank == 6)
	{
		console.log("Skill cannot go higher than 6");
		return;
	}

	//else, increment skill
	skills.set(skillName, rank+1)
}

//Decrease a skill's rank by 1
//	input - string skillName
function decrementSkill(skillName)
{
	//get skill rank
	var rank = skills.get(skillName);

	//if decrementing past floor
	if (rank == 0 || (rank == 2 && isRequired(skillName)))
	{
		console.log("Skill cannot go lower");
		return;
	}

	//else, increment skill
	skills.set(skillName, rank-1)
}

//Returns true if given skill name is a required skill
//else, false
//	input - string skillName
//	output - bool
function isRequired(skillName)
{
	switch (skillName) {
		case "Concentration (WILL)":
			return true;
		case "Perception (INT)":
			return true;
		case "Athletics (DEX)":
			return true;
		case "Stealth (DEX)":
			return true;
		case "Education (INT)":
			return true;
		case "Streetslang":
			return true;
		case "Your Home":
			return true;
		case "Brawling (DEX)":
			return true;
		case "Evasion (DEX)":
			return true;
		case "Convesation (EMP)":
			return true;
		case "Human Perception (EMP)":
			return true;
		case "Persuasion (COOL)":
			return true;
		case "First Aid (TECH)":
			return true;
		default: //else
			return false;
	}
}