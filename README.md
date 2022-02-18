# 42_philosophers

## Project 07: Creating threads and making them survive as long as possible
</br>

[![jaeskim's 42Project Score](https://badge42.herokuapp.com/api/project/opacaud/Philosophers)](https://github.com/JaeSeoKim/badge42)
</br>
</br>

Picture this: a round table around which philosophers are sitting, hoping to eat in order to survive as long as possible, if not forever.
A philosopher has one and only one fork but needs two to eat from the plate in the middle of the table. A philosopher has therefore to borrow the fork from the philosopher sitting next to him or her, in order to have two and finally eat.
</br>

Run ```make``` and then ```./philo nb_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]```
</br>

You then will see philosophers, one after another, taking forks, eating during "time_to_eat" milliseconds, sleeping during "time_to_sleep" milliseconds and thinking (waiting for forks actually), again and again, until number_of_times_each_philosopher_must_eat is reached or one philosopher dies because he or she has not eat for "time_to_die" milliseconds.
</br>

Examples:
* ```./philo 1 850 200 200```       ===> the one philo takes his or her fork and waits. Since there is no other fork to eat from the plate, he or she dies after 800ms.
* ```./philo 5 850 200 200```       ===> no philosopher should die, or not for a long time.
* ```./philo 5 850 200 200 2```     ===> the program will stop once the five philosophers ate twice each.
* ```./philo 4 450 200 200```       ===> no philosopher should die, or not for a long time.
* ```./philo 4 300 200 300```       ===> a philosopher should die

Please note that from a machine to another, results may differ. The success of this program relies on the user's machine and its calculation speed.
