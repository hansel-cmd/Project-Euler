import time

def best(divisors, max_number):
    n1, n2 = divisors
    max_number -= 1
    
    def k(max_number, number):
        _k = int(max_number / number)
        return number * (_k * (_k + 1) * 0.5)
        
    return int(k(max_number, n1) + k(max_number, n2) - k(max_number, n1 * n2))

def brute(divisors, max_number):
    total = 0
    for i in range(1, max_number):
        if i % divisors[0] == 0 or i % divisors[1] == 0:
            total += i
    return int(total)


if __name__ == "__main__":

    print("BRUTE FORCE TIME")

    now = time.time()
    print("Sum: ", brute((3,5), 1000000))
    elapsed = time.time() - now 

    print("Total Running Time: ", "{:.15f}".format(elapsed))

    print("\nBEST ALGORITHM TIME")

    now = time.time()
    print("Sum: ", best((3, 5), 1000000))
    elapsed = time.time() - now

    print("Total Running Time: ", "{:.15f}".format(elapsed))

    