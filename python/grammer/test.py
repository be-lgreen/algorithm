

def list_grammer():
    # initialize list with 0~9
    b = [i for i in range(10)]
    print(b) #[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

    b.append(10)
    print(b) #[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

    b.insert(10, 11)
    print(b) #[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 10]

    del b[10]
    print(b) #[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

    b.pop(10)
    print(b) #[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]


def set_grammer():
    li = ["12", "12", "123", "1", "2", "2", "3"]
    s = list(set(li))
    print(s)


def map_grammer():
    li = [i for i in range(5)]
    print(li)

    def func(x):
        return x*2

    result = list(map(func, li))
    print(result)


def dict_grammer():
    dict = {
        "a": 1,
        "b": 2,
        "c": 3,
        "d": 4,
        "e": 5
    }

    print(dict.get("f"))
    print(dict.keys())
    print(dict.values())


def sort_grammer():
    students = [
        ('hong', 3.9, 2016303),
        ('kim', 3.0, 2016302),
        ('choi', 4.3, 2016301),
    ]
    sorted_list = sorted(students, key=lambda student:student[1], reverse=True)
    print(sorted_list)

if __name__ == "__main__":
    sort_grammer()