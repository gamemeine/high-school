
from datetime import date, datetime

import datetime

mleko = [-1.0]
data = datetime.datetime(2022, 4, 23)
dzien = 1

owce = 600
wydajnosc = 0.5

mleko_calkowite = 0.0

popyt_normalny = 36
popyt_weekend = 100

popyt_calkowity = 0

sery = 0

while data <= datetime.datetime(2022, 9, 29):
    #wydajnosc
    if data <= datetime.datetime(2022, 6, 24):
        if dzien % 7 == 1 and dzien != 1:
            wydajnosc *= 1.04
            wydajnosc = round(wydajnosc, 2)
    else:
        if dzien % 7 == 1 and dzien != 1:
            wydajnosc *= 0.9
            wydajnosc = round(wydajnosc, 2)

    #produkcja
    mleko.append(owce * wydajnosc)
    mleko_calkowite += owce * wydajnosc

    if dzien > 6:
        sery_dzisiaj = int(mleko[dzien-6] / 6)
        sery += sery_dzisiaj

    #konsumpcja
    if data >= datetime.datetime(2022, 4, 29):
        if data.weekday() >= 5:
            popyt_calkowity += popyt_weekend

            if(sery < popyt_weekend):
                sery = 0
            else:
                sery -= popyt_weekend
        else:
            popyt_calkowity += popyt_normalny

            if(sery < popyt_normalny):
                sery = 0
            else:
                sery -= popyt_normalny
    




    #operacje daty
    data += datetime.timedelta(days=1)
    dzien += 1


# Zadanie 1
print(mleko_calkowite)
# Zadanie 2
print(popyt_calkowity)
