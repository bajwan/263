# Timing Tests of Sorting Functions

We learned a lot about sorting this past week; we now know how Bubble Sorts (yuck!), Selection Sort, Insertion Sort, Shell Sort, Heap Sort, Merge Sort, and Quick Sort work.  We learned that many algorithms have similar Big-O values, but that doesn't always tell us the whole story.

For this homework assignment we will be running timing tests on the algorithms.  Don't worry - I've already created the algorithms for you.  You can download my [sorts.h](./sorting/code_samples/sorts.h) file and include it in your homework.  It isn't terribly well documented, but all we need to know is that we call each method with a single vector of (probably) unsorted objects.

## Your Class

You will need to do a tiny bit of programming though.  I would like you to create a Celebrity class.  This class should hold the following information (state):

  - Their name
  - How badly you want to meet them (0-10, 10 being you would sell your parents to meet them [assuming you love your parents...])
  - What area they are involved in (movies, music, standup, etc.)
  - Whether or not you have met them before

You will also need to create the normal accessor and mutator functions (behavior).  Most importantly though, you must implement the operator< function such that the Celebrities are compared as follows:

  - How badly you want to meet them comes first
  - Whether or not you have met them before comes second
  - In case of a tie in the above two cases, alphabetically by name (don't worry about first and last name, just keep the entire name in a string)

This operator< function will be what allows us to sort our Celebrities with the given functions.

# Timing tests

For the following sorts, run the algorithm once on a vector<Celebrity> of your top ten celebrities.  Note the run time:

- Bubble Sort
- Selection Sort
- Insertion Sort
- Merge Sort
- Quick Sort

You can time your code run (on EOS) with the command:

```
time ./myProgram
```

```time``` will output three values; we will use the real time value:

```
real	0m0.005s
user	0m0.001s
sys	0m0.003s
```

## Real Timing Tests

Your above timing tests should all be very similar.  In the submission document, question number 1 is "Why are the runtimes so similar for the first tests?".

Now write a program that takes as input an integer.  This integer will tell us how many Celebrities to create.  Create them as such:

- Assign a random 8 characters for name (remember ASCII table, this should be easy)
- Assign a random number between 0-10 for how badly you want to meet them
- Assign a random boolean (0 or 1) to whether you've met them before

For each of the sorts listed above run your program 5 times for each of the following input values to your algorithm:

- 10
- 100
- 1000
- 10000
- 100000
- 1000000

Post your results in a table and plot them with a line graph (very simple in Excel).

## Notes

- Work in partners.  Discussion is important here (and it will save you a ton of time)
- If you are good with BASH you can automate these runs and timing collection.  If you aren't good with BASH it will be quicker just to do it manually; don't get bogged down
- Keep track of how many people are currently on the EOS machine you are using.  You can see who is logged in with the ```users``` command.  More people on can cause wierd results

## Submission

Upload your document(s) to Blackboard by the due date (on schedule).
