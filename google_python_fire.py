# http://codec.wang
# 2020/05/21

import fire


def sub(n1, n2):
    return n1 - n2


class Student(object):
    def __init__(self, name):
        self.name = name

    def welcome(self):
        return 'Hello %s' % self.name


if __name__ == "__main__":
    fire.Fire(sub)
    # fire.Fire(Student)
    # fire.Fire([1, 2, 3])
    # fire.Fire({'name': 'wang', 'age': 18})
