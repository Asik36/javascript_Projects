from utils import Utils
class LifeLines():
    def __init__(self):
        self.primeCheckFlage = True
        self.fibonacciCheckFlag = True
        self.rangeReductionFlag = True

    def prime_check(self,matrix,n):
        if(self.primeCheckFlage):
            self.primeCheckFlage = False
            if Utils.is_prime(n):
                print("The secret number is a prime number!")
                return Utils.matrix_prime_index(matrix,True)
            else:
                print("The secret number is not a prime number!")
                return Utils.matrix_prime_index(matrix,False)
        else:
            print("You have already used prime check!")
            return matrix
        
    def fibonacci_check(self,matrix,n):
        if(self.fibonacciCheckFlag):
            self.fibonacciCheckFlag = False
            if Utils.is_fibonacci(n):
                print("The secret number is in the Fibonacci series!")
                return Utils.matrix_fibonacci_index(matrix,True)
            else:
                print("The secret number is not in the Fibonacci series!")
                return Utils.matrix_fibonacci_index(matrix,False)
        else:
            print("You have already used fibonacci check!")
            return matrix
            
            
    def range_reduction(self,matrix,n): # If the player recives input about if the secret number is higher or lower, why would anybody use this???
        if(self.rangeReductionFlag):
            self.rangeReductionFlag = False
            print("Range of numbers is reducted , as well as the number of remining guesses!")
            if Utils.is_upper_half(matrix,n):
                print(f"Number is in smaller or equal then {Utils.matrix_get_size(matrix)//2}!")

                

                return Utils.matrix_cut(matrix, False)
            else:
                print(f"Number is in larger or equal then {Utils.matrix_get_size(matrix)//2+1}!")


                return Utils.matrix_cut(matrix, True)
        else:
            print("You have already used range reduction!")
            return matrix
        

        
       
if __name__ == "__main__":
    ll = LifeLines()
    matrix = [[1 for _ in range(10)] for _ in range(10)]
    try:
        Utils.print_matrix(ll.prime_check(matrix,70))
    except Exception as e:
        print(str(e))
    try:    
        Utils.print_matrix(ll.fibonacci_check(matrix,70))
    except Exception as e:
        print(str(e))

    try:
        Utils.print_matrix(ll.range_reduction(matrix,70))

    except Exception as e:
        print(str(e))
        


    