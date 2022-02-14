"""
Чтобы запустить файл установи python3.8 и в командной строке в директории с файлом пропиши
python3 main.py
"""

import csv
import random


def one_digit_2_two(number: int) -> str:
    if number < 10:
        return f'0{str(number)}'
    return str(number)


"""
Названия колонок таблицы
"""
fieldnames = ['id', 'subject', 'lesson_type', 'classroom']

subjects = ['english', 'math', 'mechanics', 'philosophy', 'sociology', 'programming']

"""
Чтобы сделать рандом пропорциональным можешь домножить список с названием на какое либо число
лично у меня распределение 3/4/2/1 а можешь убрать умножение и раскрыть скобки
['lecture', 'practice', laboratory', 'examine']
(если тебе вообще это нужно, просто тут я генерю много номеров аудиторий, а если тебе это не нужно то просто удали)
"""
lesson_types = [*['lecture']*3, *['practice']*4, *['laboratory']*2, 'examine']
classrooms = []

# Числа в range это от n до m (возможно тебе по заданию это не нужно)
for room in range(1, 50):
    for floor in range(1, 5):
        for campus in range(1, 4):
            classrooms.append(''.join((str(campus), str(floor), one_digit_2_two(room))))

with open('timetable.csv', 'w') as file:
    writer = csv.DictWriter(file, fieldnames=fieldnames, delimiter=';')
    writer.writeheader()
    for i in range(10000):  # Число 10000 это сколько строк будет в твоем csvшнике, ставь какое хочешь)
        writer.writerow({
            'id': i,
            'subject': random.choice(subjects),
            'lesson_type': random.choice(lesson_types),
            'classroom': random.choice(classrooms)
        })

