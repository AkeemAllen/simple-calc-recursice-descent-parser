### Build and Run Instructions

1. Compile with either gcc or clang: `gcc calc.c -o calc`
2. Run compiled program like any other. It takes a simple math expression as it's only argument: `./calc '2+4*3'`

### Why does this exist?

The long and short of this is I was trying to learn C. I learn by doing so I thought a simple CLI calculator would be a good project.
Natually the first question that came up was, "How do I parse and evaluate the provided mathematical expression?"

Ba da bing ba da boom, I'm building a recursive descent parser.

It's been a fun journey so far, and it turns out this one of the building blocks for developing a programming language, something else I happen to be interested in. We'll see where that goes.
