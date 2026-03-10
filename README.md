*This project has been created as part of the 42 curriculum by mlima-si.*

# Philosophers

## Description

The **Philosophers** project is part of the 42 School curriculum and explores the classic synchronization problem known as the **Dining Philosophers Problem**.

The goal of the project is to understand and implement **threading and mutex synchronization in C**. Philosophers sit around a table with a fork between each pair. In order to eat, a philosopher must pick up both the left and right fork. However, since forks are shared resources, proper synchronization is required to prevent issues such as **deadlocks, race conditions, and starvation**.

In this project, each philosopher is represented by a **thread**, and forks are protected using **mutexes**. The program simulates philosophers thinking, eating, and sleeping while ensuring the rules of the problem are respected.

The challenge lies in designing a system where philosophers can safely share forks without causing concurrency problems.

---

## Instructions

### Compilation

To compile the program, run:

```bash
make
```

This will generate the executable:

```
philo
```

### Execution

Run the program with:

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

### Parameters

| Argument | Description |
|--------|-------------|
| `number_of_philosophers` | Number of philosophers and forks |
| `time_to_die` | Time (ms) a philosopher can survive without eating |
| `time_to_eat` | Time (ms) a philosopher spends eating |
| `time_to_sleep` | Time (ms) a philosopher spends sleeping |
| `number_of_times_each_philosopher_must_eat` | *(Optional)* Simulation stops when each philosopher has eaten this many times |

### Example

```bash
./philo 5 800 200 200
```

This runs a simulation with:
- 5 philosophers
- 800 ms before a philosopher dies without eating
- 200 ms eating
- 200 ms sleeping

---

## Features

- Multithreading using **pthreads**
- Fork protection using **mutexes**
- Accurate time management for philosopher actions
- Death detection system
- Prevention of race conditions in shared resources

---

## Technical Concepts

This project focuses on several important concurrency concepts:

- **Threads** (`pthread`)
- **Mutex locks**
- **Shared resource protection**
- **Race condition prevention**
- **Deadlock avoidance**
- **Precise timing in concurrent systems**

---

## Resources

The following resources were used to understand the Dining Philosophers problem and concurrency concepts:

- https://medium.com/@ruinadd/philosophers-42-guide-the-dining-philosophers-problem-893a24bc0fe2
- https://42-cursus.gitbook.io/guide/3-rank-03/philosophers
- https://www.youtube.com/watch?v=zOpzGHwJ3MU

### AI Usage

Artificial intelligence tools were used **only as support tools during the learning process**.

AI was used for:
- Clarifying **concepts related to threads and mutexes**
- Explaining **possible strategies to avoid deadlocks**
- Reviewing **general project structure ideas**
- Helping write and improve **documentation (README)**

AI was **not used to generate the project implementation**, and all concurrency logic, synchronization, and program structure were implemented manually as part of the learning process.

---

## Author

**mlima-si**  
42 School Student
