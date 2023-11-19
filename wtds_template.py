def solve() -> None:
    """
    Identify the unknown datamon through making feed and poop queries.
    
    Call the feed and poop functions below to make feed and poop queries. Return
    from this function after calling the guess function to make a guess query.
    """
    # YOUR CODE HERE

    feed(1)
    feed(2)
    feed(1)
    feed(3)

    ls = [poop(), poop(), poop(), poop()]

    if ls == [3, 2, 1, 1]:
        guess("heapeon") # Guess heap
    elif ls == [1, 2, 1, 3]:
        guess("queueon") # Guess queue
    elif ls == [3, 1, 2, 1]:
        guess("stackeon") # Guess stack
    else:
        guess('YOUR MOM')


def feed(i: int) -> str:
    """
    Feed a number to the Datamon. Returns OK if successful.
    """
    print('feed', i, flush=True)
    response = input()
    if response == 'WRONG_ANSWER':
        exit()
    return response


def poop() -> int:
    """
    Get the Datamon to poop out a number. Returns the number pooped out.
    """
    print('poop', flush=True)
    response = input()
    if response == 'WRONG_ANSWER':
        exit()
    return int(response)


def guess(s: str) -> str:
    """
    Guess the species of the Datamon and end this test case. Returns CORRECT if
    the guess is correct. Exits otherwise.
    """
    print('guess', s, flush=True)
    response = input()
    if response == 'WRONG_ANSWER':
        exit()
    return response


def main():
    T = int(input())
    for _ in range(T):
        solve()


if __name__ == '__main__':
    main()
