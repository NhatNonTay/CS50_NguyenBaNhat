import csv
import sys

FILENAME = 'team.csv'

def load_team():
    """Load team from the CSV file"""
    team = []
    try:
        with open(FILENAME, newline='', encoding='utf-8') as csvfile:
            reader = csv.DictReader(csvfile)
            for row in reader:
                team.append(row)
    except FileNotFoundError:
        pass  # If the file doesn't exist, return an empty team
    return team

def save_team(team):
    """Save team to the CSV file"""
    with open(FILENAME, 'w', newline='', encoding='utf-8') as csvfile:
        fieldnames = ['name', 'position', 'number']
        writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
        writer.writeheader()
        writer.writerows(team)

def add_player(team):
    """Add a new player to the team"""
    name = input("Enter player's name: ")
    position = input("Enter player's position: ")
    number = input("Enter player's number: ")
    
    # Check if the number is unique
    for player in team:
        if player['number'] == number:
            print(f"A player with number {number} already exists.")
            return

    team.append({'name': name, 'position': position, 'number': number})

def remove_player(team):
    """Remove a player from the team"""
    number = input("Enter the number of the player to remove: ")
    for player in team:
        if player['number'] == number:
            team.remove(player)
            print(f"Player {number} removed.")
            return
    print(f"No player with number {number} found.")

def display_team(team):
    """Display the team"""
    if not team:
        print("No players in the team.")
        return
    for player in team:
        print(f"Name: {player['name']}, Position: {player['position']}, Number: {player['number']}")

def main():
    team = load_team()

    while True:
        print("\nTeam Manager")
        print("1. Add player")
        print("2. Remove player")
        print("3. Display team")
        print("4. Save and exit")
        choice = input("Enter your choice: ")

        if choice == '1':
            add_player(team)
        elif choice == '2':
            remove_player(team)
        elif choice == '3':
            display_team(team)
        elif choice == '4':
            save_team(team)
            print("Team saved. Exiting.")
            break
        else:
            print("Invalid choice. Please enter a number from 1 to 4.")

if __name__ == "__main__":
    main()
