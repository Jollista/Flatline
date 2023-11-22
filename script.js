//default header image
var defImage=document.getElementById("header-image").getAttribute('src');

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
//Derived stats
stats.set('HP', 20);
stats.set('HUM', 20);

//Map of skills (names, rank)
const skills = new Map();

//initialize required skills
skills.set('Concentration (WILL)', 2);
skills.set('Perception (INT)', 2);
skills.set('Athletics (DEX)', 2);
skills.set('Stealth (DEX)', 2);
skills.set('Education (INT)', 2);
skills.set('Streetslang (INT)', 2);
skills.set('Your Home (INT)', 2);
skills.set('Brawling (DEX)', 2);
skills.set('Evasion (DEX)', 2);
skills.set('Convesation (EMP)', 2);
skills.set('Human Perception (EMP)', 2);
skills.set('Persuasion (COOL)', 2);
skills.set('First Aid (TECH)', 2);

var maxSkillPoints = 86;
var remSkillPoints = 60;

var humanity = 10 * stats.get("EMP")

/*
	STEP 1: SELECT A ROLE
*/

//Load an image to header-image
function loadImage(image=defImage)
{
	var headerImage = document.getElementById("header-image");
	headerImage.setAttribute('src', image);
}

//Select a role
function selectRole(role)
{
	//set button text to role
	var k = document.getElementById("roleButton");
	k.innerText = role;

	//update myRole to role
	myRole = role;

	//set image to role's image
	defImage = document.getElementById("header-image").getAttribute('src');
}

/*
	STEP 3: BUY YOUR STATS
*/

//increase the rank of a stat by 1
//	input - string statName
function incrementStat(statName) 
{
	//get current stat rank
	var rank = stats.get(statName);

	//if cannot increment, print error and return
	if (rank == 8 || remStatPoints <= 0)
	{
		console.log("STATS cannot be higher than 8 or exceeding remaining stat points");
		return;
	}

	//update stat rank to rank+1
	stats.set(statName, rank+1);
	//update point tracker
	remStatPoints--;

	//update stat point display
	var k = document.getElementById("statPointDisplay");
	k.innerText = "Points: " + remStatPoints + "/"+maxStatPoints;
	//update stat specific display
	//update stat totals
	document.getElementsByName(statName.toLowerCase()+"Total").forEach(function(ele, idx) {
		ele.textContent = rank+1;
	});
	//update relevant skill bases
	document.getElementsByName(statName.toLowerCase()+"Base").forEach(function(ele, idx) {
		ele.textContent -= -1;
	});
	//update humanity
	humanity = stats.get("EMP")*10;
	document.getElementById("Humanity").innerText= humanity + " / " + (stats.get("EMP")*10);
}

//decrease the rank of a stat by 1
//	input - string statName
function decrementStat(statName) 
{
	//get current stat rank
	var rank = stats.get(statName);

	//if cannot decrement, print error and return
	if (rank == 2)
	{
		console.log("STATS cannot be lower than 2");
		return;
	}

	//update stat rank to rank-1
	stats.set(statName, rank-1);
	//update point tracker
	remStatPoints++;

	//update display
	var k = document.getElementById("statPointDisplay");
	k.innerText = "Points: " + remStatPoints + "/"+maxStatPoints;
	//update stat specific display in both stats and skills
	//update stat totals
	document.getElementsByName(statName.toLowerCase()+"Total").forEach(function(ele, idx) {
		ele.textContent = rank-1;
	});
	//update relevant skill bases
	document.getElementsByName(statName.toLowerCase()+"Base").forEach(function(ele, idx) {
		ele.textContent -= 1;
	});
	//update humanity
	humanity = stats.get("EMP")*10;
	document.getElementById("Humanity").innerText= humanity + " / " + (stats.get("EMP")*10);
}

/*
	STEP 5: SET YOUR SKILLS
*/

//Increase a skill's rank by 1
//	input - string skillName
function incrementSkill(skillName)
{
	//initialize skill to 0 if it doesn't exist already
	if (!skills.has(skillName))
	{
		skills.set(skillName, 0);
	}

	//check for difficult skills and track remSkillPoints accordingly
	var difficulty = 1;
	var nameMinusDifficulty = skillName;
	if (skillName.includes("(x2)"))
	{

		difficulty = 2;
		// cut out (x2)
		nameMinusDifficulty = skillName.replace(" (x2)", "");
	}

	//get skill rank
	var rank = skills.get(skillName);

	//if incrementing past ceiling
	if (rank == 6 || remSkillPoints <= 0)
	{
		console.log("Skill cannot go higher than 6");
		return;
	}

	//else, increment skill
	skills.set(skillName, rank+1);
	//update point tracker
	remSkillPoints -= 1 * difficulty;

	//update display
	document.getElementById("skillPointDisplay").innerText = "Points: " + remSkillPoints + "/"+maxSkillPoints; //update point total display
	var stat = nameMinusDifficulty.substring(nameMinusDifficulty.indexOf("(")+1, nameMinusDifficulty.indexOf(")")); //get name of stat
	document.getElementById(skillName + " Rank").innerText=rank+1; //update displayed rank
	document.getElementById(skillName + " Base").innerText=rank+1+stats.get(stat); //update displayed base (level + stat)
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

	//check for difficult skills and track remSkillPoints accordingly
	var difficulty = 1;
	var nameMinusDifficulty = skillName;
	if (skillName.includes("(x2)"))
	{

		difficulty = 2;
		// cut out (x2)
		nameMinusDifficulty = skillName.replace(" (x2)", "");
	}

	//else, increment skill
	skills.set(skillName, rank-1)
	//update point tracker
	remSkillPoints += 1 * difficulty;

	//update display
	document.getElementById("skillPointDisplay").innerText = "Points: " + remSkillPoints + "/"+maxSkillPoints; //update point total display
	var stat = nameMinusDifficulty.substring(nameMinusDifficulty.indexOf("(")+1, nameMinusDifficulty.indexOf(")")); //get name of stat
	document.getElementById(skillName + " Rank").innerText=rank-1; //update displayed rank
	document.getElementById(skillName + " Base").innerText=rank-1+stats.get(stat); //update displayed base (level + stat)

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
		case "Streetslang (INT)":
			return true;
		case "Your Home (INT)":
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


/*
	BUY YOUR GEAR
 */

var funds = 2550+800;
var soulValue = 1500;
var inventory = new Map();

function updateGearDisplay() 
{
	//update inventory
	var inventoryString ="";
	inventory.forEach((values, keys) => {
		inventoryString += "- " + keys + "\t\t x " + values + "\n";
	});
	document.getElementById("InventoryList").innerText=inventoryString;
}

function purchase (item, cost) 
{
	//cost check
	if (cost > funds)
		return;

	//remove funds, add to inventory
	funds -= cost;
	if (!inventory.has(item))
	
		inventory.set(item, 1);
	else
		inventory.set(item, inventory.get(item)+1);

	//update display
	updateGearDisplay();
	//update funds
	document.getElementById("Funds").innerText=funds+" eb";

	return true;
}

function sell (item, cost) 
{
	//quantity check
	if (!inventory.has(item) || inventory.get(item) == 0) //no transaction if no item
		return;
	
	//add funds and decrement item
	funds += cost;
	inventory.set(item, inventory.get(item)-1);

	//if no more of item
	if (inventory.get(item) <= 0)
		inventory.delete(item);

	//update display
	updateGearDisplay();
	//update funds
	document.getElementById("Funds").innerText=funds+" eb";

	return true;
}

function purchaseCyberware (item, ebCost, humCost) 
{
	//don't buy if exceeds humanity
	if (humCost >= humanity)
		return;

	//remove humanity
	if (purchase(item, ebCost))
		humanity -= humCost;

	//update humanity display
	document.getElementById("Humanity").innerText= humanity + " / " + (stats.get("EMP")*10);

	return true;
}

function sellCyberware (item, ebCost, humCost) 
{
	//remove humanity
	if (sell(item, ebCost))
		humanity += humCost;

	//update humanity display
	document.getElementById("Humanity").innerText= humanity + " / " + (stats.get("EMP")*10) + " HUM";
}

function checkSoul() 
{
	var checkbox = document.getElementById('soul');
	if (checkbox.checked)
	{
		//add extra stuff
		humanity -= 7;
		inventory.set("Complimentary Neural Link", 1);
		funds += soulValue;
	}
	else //remove extra stuff
	{
		funds -= soulValue;
		sellCyberware("Complimentary Neural Link", 0, 7);
	}
	
	//update display
	document.getElementById("Funds").innerText=funds+" eb";
	document.getElementById("Humanity").innerText= humanity + " / " + (stats.get("EMP")*10) + " HUM";
	updateGearDisplay();
}