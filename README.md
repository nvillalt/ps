## **Push Swap**
> Because Swap Push isn't as natural

### **Aim**
This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed, you'll have to manipulate various types of algorithms and choose the most appropiate solution (out of many) for an optimized data sorting.

### **Documentation and Development**
This project was an absolute challenge to develop. In order to properly understand the logic behind it, I learnt about [doubly linked circular lists](https://www.sanfoundry.com/c-program-circular-doubly-linked-list/): something not required for this project but that I wanted to learn about nontheless. It proved to be a real challenge but one that I enjoyed and ended up being incredibly satisfactory once I understood it.
Furthermore, parsing the arguments and choosing the correct algorithm, is a beast on its own. 
- When it came to parsing, I mostly checked the errors suggested by the subject as well as asked my peers to see in which ways they could break my program (plenty of). I will highlight the most problematic parses, in my opinion.
    - Overflow and double overflow.
    - Succession of several `0`.
    - Repetition of numbers after being input like this: `6`, `06`.
    - Passing `-` and `+` as arguments (since `atoi` understands both as `0`).
- When it came to the actual algorithm, I documented my project with the following articles and webpages:
    - [Push Swap Visualizer](http://push-swap.site)
    - [A Journey to Finding the Most Efficient Sorting Algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
    - [The Least Amount of Movements with Two Stacks](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
    - [Push Swap: Oceano's youtube video](https://www.youtube.com/watch?v=OaG81sDEpVk)

### Bonus 
> Currently under development

### Testing
This project can be tested by using the provided checker binary (part of the project's resources) and also by checking the [Push Swap Visualizer web](http://push-swap.site).

Enjoy!
