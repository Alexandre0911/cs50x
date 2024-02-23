import cs50


def main():
    while True:
        change = cs50.get_float("Change: ")
        if change > 0:
            break

    print(give_change(change))


def give_change(change):
    coins_given = 0
    available_coins = [.25, .10, .05, .01]

    for coin in available_coins:
        while change >= coin:
            change = round(change - coin, 2)
            coins_given += 1

    return coins_given


main()
