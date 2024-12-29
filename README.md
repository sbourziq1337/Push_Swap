# What is Push_swap:

Push_swap is a project where you sort data on a stack using a limited set of instructions and aim for the lowest possible number of moves. To succeed, you’ll need to explore and implement various algorithms, choosing the most optimized solution for efficient data sorting.

![](https://miro.medium.com/v2/resize:fit:700/1*rXKk8juFHQaLzI-uJyEVog.png)

### Allowed Actions:

You can manipulate two stacks with the following actions:

- **sa, sb, ss**: Swapping elements at the top of stacks.
- **ra, rb, rr**: Rotating stacks (top to bottom).
- **rra, rrb, rrr**: Reverse rotating stacks (bottom to top).
- **pa, pb**: Pushing elements from one stack to the other.

**How the actions work:**

![](https://miro.medium.com/v2/resize:fit:700/1*dAHbFo-fEko25X-C8CVeKw.png)  
![](https://miro.medium.com/v2/resize:fit:700/1*Iji-cUJbgJ1BRmLjT9Qqkw.png)  
![](https://miro.medium.com/v2/resize:fit:700/1*v8rjNThxCvEIkbDNjomCZg.png)  
![](https://miro.medium.com/v2/resize:fit:700/1*kE_2S1E4IoJxRF4eVt6TAQ.png)

---

# Which Algorithm I’ve Used?

### The Turk Algorithm

The **Turk Algorithm** is my unique, hardcoded approach to solving Push_swap. Inspired by the [Mechanical Turk](https://en.wikipedia.org/wiki/Mechanical_Turk), it’s not an elegant or sophisticated solution, but it works. Like the historical automaton with a human hidden inside, this algorithm gets the job done through brute force and manual logic rather than advanced optimization.

![](https://miro.medium.com/v2/resize:fit:600/1*ZLKF3qJ75poRylB9g8wM5w.gif)

### How the Turk Algorithm Works

1. **Initial Setup**: Start with one sorted stack (descending order) and an unsorted stack.
2. **Transfer Phase**: Elements are moved from the unsorted stack to the sorted stack while maintaining the order.
3. **Sorting Phase**: Use pushes, swaps, and rotations to reorder the first stack into the desired arrangement.
4. **Circular Checks**: Integrate checks for circular sorting patterns to reduce unnecessary moves and improve efficiency.

While not the most refined solution, the Turk Algorithm is a reliable, no-frills method. It’s a testament to creativity over complexity and gets the job done!

#### Glad you liked it! Let me know if you need help with anything else for your GitHub or project. Good luck with your Push_swap journey! 🚀