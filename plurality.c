#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

int get_index(string name)
{   //return candidates' index by searching its name
    for(int i = 0; i < candidate_count; i++)
     if (strcmp(candidates[i].name, name) == 0)
            return i;
    return -1;
}
// Update vote totals given a new vote
bool vote(string name)
{
    // TODO： figure out the index corresponding to the name
    int candidate_index = get_index(name);
    if (candidate_index != -1)
    {
        //increment vote of that candidate
        candidates[candidate_index].votes++;
        return true;
    }
    return false;

}
int get_max(void)
{
    //binary search maximum votes
    int max_votes = candidates[0].votes;
    for(int i = 0; i < candidate_count; i++)
    if (candidates[i].votes > max_votes)
        max_votes = candidates[i].votes;

    return max_votes;

}
// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO: figuring out the maximum number of votes
    int max_votes = get_max();
    //print the name of candidates who got the maximum votes
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max_votes)
            printf("%s\n", candidates[i].name);

    }


}

