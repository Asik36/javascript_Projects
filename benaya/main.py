import random
import random
from lifelines import LifeLines 
from utils import Utils as utils


NUM_ATTEMPTS = 10

LIMIT_EASY = 30 
LIMIT_MEDUIM = 50
LIMIT_HARD = 100 

class Game():
    def __init__(self):
        self.limit = LIMIT_EASY 
        self.secret_number = 0
        self.turnNum = 1

        self.attempts = NUM_ATTEMPTS
        self.matrix = []
        self.lifeLines = LifeLines()

        




    def set_difficulty(self):
        print("*** Choose Difficulty Level ***")
        print("1. Easy (numbers between 1 and 30)")
        print("2. Medium (numbers between 1 and 50)")
        print("3. Hard (numbers between 1 and 100)")
        while(True):
            difficulty= input().lower()

            if difficulty == '1'  or difficulty == 'easy':
                self.limit = LIMIT_EASY
                difficulty = 'Easy'
                break
            elif difficulty == '2' or  difficulty == 'medium':
                self.limit = LIMIT_MEDUIM
                difficulty = 'Medium'
                break
            elif difficulty == '3' or  difficulty == 'hard':
                self.limit = LIMIT_HARD
                difficulty = 'Hard'
                break
            else:
                print("Invalid input! Please Choose Difficulty Level Again.")
        self.matrix = [[1 for _ in range(10)] for _ in range(self.limit//10)]
        print(f"You Choose {difficulty} Mode! Guess a number between 1 and {self.limit}!")
        self.board()
    def generate_secret_number(self):
        self.secret_number = random.randint(1, self.limit)
    
    def board(self):
        utils.print_matrix(self.matrix)

    def user_input(self):
        while(True):
            ui = input()
            if ui.isnumeric(): 
                if(int(ui)>0 and int(ui)<=self.limit):
                    return int(ui)
                else:
                    print(f"Please enter a number between 1 and {self.limit}") 

            elif ui.lower() == "lifelines": 
                self.life_lines()
            
             
            elif ui.lower() == "prime check" or ui.lower() == "prime" or ui.lower() == "1.":
                self.matrix = self.lifeLines.prime_check(self.matrix,self.secret_number)
                self.board()
            elif ui.lower() == "fibonacci check" or ui.lower() == "fibonacci" or ui.lower() == "2.": 
                self.matrix = self.lifeLines.fibonacci_check(self.matrix,self.secret_number)
                self.board()
            elif ui.lower() == "range reduction" or ui.lower() == "reduction" or ui.lower() == "range" or ui.lower() == "3.": # range reduction lifelnie
                if(self.lifeLines.rangeReductionFlag):
                    self.attempts //=2 
                self.matrix = self.lifeLines.range_reduction(self.matrix,self.secret_number)
                self.board()
                
                
            else:
                print("Invalid command. Use 'Lifelines' to see the list of lifelines.")
        

    def check_guess(self, guess):
        distance = guess-self.secret_number 
        if distance == 0 : 
            print(f"Congratulations! You guessed the correct number in {self.turnNum} tries.")
            exit() 
        elif distance > 0 :
            print(f"The number is somewhere lower! {self.attempts-1} attempts left")

        elif distance < 0 : 
            print(f"The number is somewhere higher! {self.attempts-1} attempts left")
        utils.remove_number(self.matrix, guess)
        self.board()
        return False
    
    def life_lines(self):
        print("*** List of Life_Lines ***")
        print("1. prime check    : Find out if the secret number is a prime number or not")
        print("2. fibonacci check: Find out if the secret number is a Fibonacci number or not")
        print("3. Range reduction: reduce range of possible numbers by half , as well as the amount of remining attampts")

  
    def game_loop(self):
        win = False
        while self.attempts >= 0 or win: 
            if(self.attempts == 0):
                print(f"Opps, you ran out of attempts. The secret number was {self.secret_number}. Maybe the next one will be the charm!") 
                exit()
            guess = self.user_input() 
            win = self.check_guess(guess)
            self.attempts -= 1
            self.turnNum += 1
           
          

    def start_game(self):
        self.set_difficulty()
        self.generate_secret_number()
        print("(You have only 3 life lines Write 'Lifelines' to see the list of Lifelines)")
        self.game_loop()

g = Game()
g.start_game()