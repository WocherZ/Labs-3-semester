import matplotlib.pyplot as plt
import os.path
import time

from config import path


def isint(number):
    if int(number) == float(number):
        return True
    else:
        return False


try:
    while True:
        time1 = os.path.getmtime(path)

        if time.time() - time1 < 1:
            data = []
            with open(path, 'r', encoding='utf-8') as file:
                lines = file.readlines()
                intervals = int(lines[0].split(' ')[0])
                length = float(lines[0].split(' ')[1])
                start = float(lines[0].split(' ')[2])
                flag_show = lines[0].split(' ')[3].rstrip()
                show = True if flag_show == "T" else False
                for i in range(1, len(lines)):
                    line = lines[i]
                    data.append(int(line.split(": ")[-1].rstrip()))

            index = []
            for i in range(intervals):
                first = start + length * i
                last = start + length * (i + 1)

                if isint(first):
                    first = int(first)
                if isint(last):
                    last = int(last)

                index.append(str(first) + " - " + str(last))

            values = data
            plt.bar(index, values, width=1, edgecolor='black', linewidth=0.2)

            if show:
                plt.title("Histogram")
                plt.xlabel("Intervals")
                plt.ylabel("Numbers")
                plt.yticks([x for x in range(0, max(values) + 1)])
                plt.show()

            time.sleep(1)

except Exception as ex:
    print(ex)

