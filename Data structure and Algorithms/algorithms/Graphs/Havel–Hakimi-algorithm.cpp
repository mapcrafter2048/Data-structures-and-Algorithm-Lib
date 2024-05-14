#include <iostream>
#include <vector>
#include <algorithm>

bool havelHakimi(std::vector<int> &sequence)
{
    // Remove all zeros from the sequence
    sequence.erase(std::remove(sequence.begin(), sequence.end(), 0), sequence.end());

    // Sort the sequence in non-increasing order
    std::sort(sequence.rbegin(), sequence.rend());

    while (!sequence.empty())
    {
        // Check if the first element is greater than the remaining elements
        if (sequence[0] > sequence.size() - 1)
        {
            return false;
        }

        // Subtract 1 from the first element
        int n = sequence[0];
        sequence.erase(sequence.begin());

        // Subtract 1 from the next n elements
        for (int i = 0; i < n; i++)
        {
            sequence[i]--;
        }

        // Remove all zeros from the sequence
        sequence.erase(std::remove(sequence.begin(), sequence.end(), 0), sequence.end());

        // Sort the sequence in non-increasing order
        std::sort(sequence.rbegin(), sequence.rend());
    }

    return true;
}

int main()
{
    std::vector<int> sequence = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    bool result = havelHakimi(sequence);

    if (result)
    {
        std::cout << "The sequence is graphical." << std::endl;
    }
    else
    {
        std::cout << "The sequence is not graphical." << std::endl;
    }

    return 0;
}