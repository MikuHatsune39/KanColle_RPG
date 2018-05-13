print("Story: You have just arived at the navel district after beening")
print("recruted to join the fleet.")

print(" ")
print("???: Hello and welcome to the fleet my name is Shimakaze,")
print("I'm the fastest ship around, what's your name?")

name = input("Type your name and hit \"ENTER\": ")

print(" ")
print("%s: My name is %s." % (name, name))

print(" ")
print("Shimakaze: Well then it's nice to meet you %s!" % (name))
print("Wan'na race?") 

def yn_race():
	yn = input("Type \"Yes\" or \"No\" and hit \"ENTER\": ").lower()
	if yn == "yes" or yn == "y":
		print(("%s: Sure, your on!" % (name)))
		return True
	elif yn == "no" or yn == "n":
		print(("%s: Mabye another time." % (name)))
		return True
	else:
		print("Please type \"Yes\" or \"No\" and hit \"ENTER\".")
		yn_race()
yn_race()
