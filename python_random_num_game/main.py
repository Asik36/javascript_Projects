import random
from lifelines import LifeLines 
from utils import Utils as ut

ATTEMPTS_NUM = 10

EASY_LIMIT = 30 
MEDUIM_LIMIT = 50
HARD_LIMIT = 100 

class Game():
    def __init__(self):
        self.limit = MEDUIM_LIMIT #default limit
        self.secret_number = 0
        self.attempts = ATTEMPTS_NUM
        self.turn = 1
        self.matrix = []
        self.lifeLines = LifeLines()

        # flags to check if a lifeline was alredy used:




    def set_difficulty(self):
        print("*** Choose Difficulty Level ***")
        print("1. Easy (numbers between 1 and 30)")
        print("2. Medium (numbers between 1 and 50)")
        print("3. Hard (numbers between 1 and 100)")
        while(True):
            difficulty= input().lower()

            if difficulty == '1' or difficulty == 'numbers between 1 and 10' or difficulty == 'easy':
                self.limit = EASY_LIMIT
                difficulty = 'Easy'
                break
            elif difficulty == '2' or difficulty == 'numbers between 1 and 100' or difficulty == 'medium':
                self.limit = MEDUIM_LIMIT
                difficulty = 'Medium'
                break
            elif difficulty == '3' or difficulty == 'numbers between 1 and 100' or difficulty == 'hard':
                self.limit = HARD_LIMIT
                difficulty = 'Hard'
                break
            else:
                print("Invalid input! Please try again.")
        self.matrix = [[1 for _ in range(10)] for _ in range(self.limit//10)] # Comperhension!!! 🤯🤯🤯
        print(f"You Choose {difficulty} Mode! Guess a number between 1 and {self.limit}!")

    def generate_secret_number(self):
        self.secret_number = random.randint(1, self.limit)
        
    def user_input(self):
        while(True):
            ui = input()
            if ui.isnumeric(): # user inputs a number
                if(int(ui)>0 and int(ui)<=self.limit):
                    if(self.matrix[(int(ui)-1)//10][(int(ui)-1)%10] == 0):
                        print("You've already tried this number!")
                    else:
                        return int(ui)
                else:
                    print(f"Please enter a number between 1 and {self.limit}") # number is out of range

            elif ui.lower() == "help": #show commands
                self.help()
            elif ui.lower() == "numbers": #shows numbers 
                self.numbers()
            elif ui.lower() == "exit": # exit the game
                exit() 
            # use a life line:
            elif ui.lower() == "prime check" or ui.lower() == "prime" or ui.lower() == "1.": # prime check lifeline
              
                self.matrix = self.lifeLines.prime_check(self.matrix,self.secret_number)
            elif ui.lower() == "fibonacci check" or ui.lower() == "fibonacci" or ui.lower() == "2.": # Fibonacci check lifeline
                self.matrix = self.lifeLines.fibonacci_check(self.matrix,self.secret_number)
            elif ui.lower() == "range reduction" or ui.lower() == "reduction" or ui.lower() == "range" or ui.lower() == "3.": # range reduction lifelnie
                if(self.lifeLines.rangeReductionFlag):
                    self.attempts //=2 # cut the ammount of attempts by half
                self.matrix = self.lifeLines.range_reduction(self.matrix,self.secret_number)
                
            else:
                print("Invalid command. Use 'help' to see the list of commands.")
        
            
   
    def numbers(self):
        ut.print_matrix(self.matrix)

    
    def check_guess(self, guess):
        distance = guess-self.secret_number 
        if distance == 0 : # if user's guess is correct
            print(f"Congratulations! You guessed the correct number in {self.turn} tries.")
            exit() 
        elif distance > 0 :
            print(f"The number is somewhere lower! {self.attempts-1} attempts left")

        elif distance < 0 : 
            print(f"The number is somewhere higher! {self.attempts-1} attempts left")
        ut.remove_number(self.matrix, guess)
        return False

    def help(self):
        print("*** List of Commands ***")
        print("*any number* : input any number from the pool and try to guess the secret number! number of attempts will decrease by one")
        print("numbers: show the current list or remaining possible guesses")
        print("exit: exits the game , thus admiting deaft")
        print("Life Lines: ")
        print("1. prime check    : Find out if the secret number is prime or not")
        print("2. fibonacci check: Find out if the secret number is a Fibonacci number or not")
        print("3. Range reduction: Norrow down the range of possible numbers by half , as well as the amount of remining attampts")

       
    def game_loop(self):
        win = False
        while self.attempts >= 0 or win: #while loop until user guesses the correct number
            if(self.attempts == 0):
                print(f"Sorry, you ran out of attempts. The secret number was {self.secret_number}. Better luck next time!") 
                exit()
            guess = self.user_input() # user's number 
            win = self.check_guess(guess)
            self.attempts -= 1
            self.turn += 1
           
          

    def start_game(self):
        self.set_difficulty()
        self.generate_secret_number()
        print("(Use 'help' to see the list of commands)")
        self.game_loop()

g = Game()
g.start_game()
