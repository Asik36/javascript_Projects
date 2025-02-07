import random
class Utils():
    def is_prime(n):
            if n <= 1:
                return False
            for i in range(2, int(n**0.5) + 1):
                if n % i == 0:
                    return False
            return True

    def matrix_prime_index(matrix, bool = True):
         for i in range(len(matrix)):
              for j in range(len(matrix[i])):
                    if Utils.is_prime((j+i*10)+1):
                        if not bool:
                            matrix[i][j] = bool
                    else:
                        if bool:
                            matrix[i][j] = not bool   
         return matrix
   
    
    def is_fibonacci(n):
         x, y = 0, 1
         while y < n:
             x, y = y, x + y
         return y == n
    def is_upper_half(matrix,n):
        return n < Utils.matrix_get_size(matrix)//2

    def matrix_cut(matrix,bool):
        size = Utils.matrix_get_size(matrix)//2
        if(bool):
            for i in range(size):
                matrix[i//10][i%10] = False
        else:
            for i in range(size, Utils.matrix_get_size(matrix)):
                matrix[i//10][i%10] = False

        return matrix

    def matrix_fibonacci_index(matrix, bool = True):
        for i in range(len(matrix)):
            for j in range(len(matrix[i])):
                if Utils.is_fibonacci(j+i*10+1):
                    if not bool:
                        matrix[i][j] = False
                else:
                    if bool:
                        matrix[i][j] = False   
        return matrix
    def matrix_get_size(matrix):
        return len(matrix)*len(matrix[0])
    
    def remove_number(matrix,n):
        n=n-1
        matrix[n//10][n%10] = 0
        return matrix

    def print_matrix(matrix):
          guessed_symbol = "--"
          for i in range(len(matrix)):
                for j in range(len(matrix[i])):
                    if(matrix[i][j]):
                        print(f"{str(j+i*len(matrix[i])+1):5s}", end= "")
                    else:
                        print(f"{guessed_symbol:3s}" , end = "  ")

                print("\n")


    
    

if __name__ == '__main__':
    matrix = [[1 for _ in range(10)] for _ in range(3)] 
    #matrix = Utils.matrix_prime_index(matrix)
    #matrix = Utils.matrix_fibonacci_index(matrix)
    matrix = Utils.matrix_cut(matrix,5)
    Utils.print_matrix(matrix)

    #Utilties.matrix_prime_index(matrix)




    



        

         