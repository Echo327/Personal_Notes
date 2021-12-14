# Agile Software Development

## How and Why

### Waterfall _Model_
* Royce 1970
> System Requirements -\>/<- Software Requirements -\>/<- Analysis -\>/<- Program Design -\>/<- Coding -\>/<- Testing -\>/<- Operations

* Updated/Modern
> Feasibility Study -\>/<- Requirements -\>/<- Specification -\>/<- Global Design -\>/<- Detailed Design -\>/<- Implementation -\>/<- V & V -\>/<- Distribution

The above **theoretical** model _Drawbacks/Inconveniences:_
* Late appearance of code; code provides a more direct feedback for feasibility and often times problems appear only when coding, late appearance of code means these problems will only appear later
* Doesn't take into consideration changes during steps
* Maintenance activity not included
* Division of labor hampering Total Quality Management
* Impedance mismatches between analysis, design, and implementation (due to lack of communication)
* Highly synchronous model

**Agile** adresses the above problems while also rejecting the problem-prone *upfront* requirements phase (**requirements change** over time; the time spent formalising requirements should be minimised). This also **reduces waste** because of requirements not being met (ex. using Lean). *Agile replaces requirements with user stories.*

Some concrete examples of how agile methodologies address these:
> Beck (XP): Requirements gathering is an activity that provides details just before it is needed in development.
> Cohn (SCRUM): All work occurs within the repeated cycle of sprints with the absence of upfront analysis or design phase.
> Poppendieck (Lean): Requirements should be more aptly called candidate solutions and not set in stone. "separating requirements from implementation is just another form of handover" 

## Manifesto (2001)
> agilemanifesto.org

```
Individuals and Interactions            >               Processes and Tools
Working Software                        >               Comprehensive Documentation
Customer Collaboration                  >               Contract Negotiation
Responding to Change                    >               Following a Plan
```

## The 12 Principles *(not verbatim)* and Values:
*  **New and reduced role for manager**
No assignment of tasks to project members by project manager. The team self-organises itself instead.

> 11. **Do not over-manage developers**; the best architectures, requirements, and designs emerge from self-organizing teams.

> 5. Build projects around motivated individuals giving them the environment they need, **support, and trust**.

*  **No "Big Upfront" steps**
Coding to produce software starts right away. Design and reevaluation of requirements are assessed continuously during the coding process instead of being fixed from the start.

> 1. Highest priority is to **satisfy customer** through early and continuous delivery of valuable software.

> 3. **Deliver working software frequently**; give preference to shorter timescales.

*  **Iterative development**
Project members communicate on a regular basis. For example, every day, or every few days, or every few weeks depending on the scope of the project in a more progressive way. *i.e.* Development cycles should last from one day to a few weeks requiring each cycle to have elicitation, design, development, and testing on a usually limited scope.

> 4. Business people and developers should **work together**.

> 2. Welcome changing requirements, *even late in development*. The **ability to change gives competitive advantage**.

> 6. **Face-to-face conversation** is the most efficient and effective way for *conveying information*.

> 8. Promote sustainable development: **maintaining constant pace**; *and avoid crunch?*

> 12. Communicate to **reflect on successes and failures** in order to **adjust team behaviour accordingly**.

*  **Limited, negotiated scope**
System does exactly what's needed *i.e.* build functionality that is strictly needed; this reduces waste (virtual and physical).

> 10. **Simplicity** *-the art of maximising the amount of work not done-* is essential; write simple code as much as you can, or in other words do not leave your code complicated and personal, make it simple, easy to read, and accessible (in terms of readability) to everyone.

> **Negotiator Scope**
> [Beck 05] Extreme Programming Explained by Kent Beck, Cynthia Andres
> 
>>
>> Write contracts for software development that fix time, costs, and quality but call for **ongoing negotiation** of the precise scope of the system. Reduce risk by signing a **sequence of short contracts** instead of one long one.
>>
>
>> You can move in the direction of negotiated scope. Big, long contracts can be split in half or thirds, with the optional part to be exercised only if both parties agree. Contracts with high costs for change requests can be written with less scope fixed up front and lower costs for changes.
>
> In other words, (blind) commitment to (both) delivery date and a specific set of functionalities do not mix well. Sometimes focusing on delivery date while forgoing some functionalities is needed while other times delivery date needs to be flexible in regards to a certain set of functionalities. 

*  **Focus on quality achieved through testing**
Testing makes for better quality products.

> 7. (Tested) **Working software** is the **primary measure of progress**.

> 9. **Continuous attention** to technical excellence and good design enhances agility.

## Updated Principles

### Organisational Principles
*mostly from SCRUM, some from XP*

1. Put the customer at the center

> Build the right system, not just build one system right.

**Real/Actual** customers should be involved not only at the beginning and end but also in the development phase to make sure that the system that is actually desired/expected is being built. Documents/requirements that "replace" the customer can only lead to waste. This also helps build a relationship between all parties involved in the project.

> XP: Embed the customer in the project with the developers (although this can be difficult to implement and lacks diversity i.e. one customer is not representative of many customers)
> SCRUM: defines a product owner who decides after an iteration of development whether it is acceptable or not (works better as product owner is committed profesionally to provide the right system)

***Customer involvement doesn't replace requirements but complements it.***

2. Accept change
In software engineering, extendibility is defined as the ability to change easily in response to changing user requirements. One of the best techniques to achieve this is object-oriented programming. Agile puts extendibility in a very abstract manner; OO-programming still therefore remains a good way of achieving this. 

3. Let the team self-organise

> The team members doing the actual work manage themselves. The SCRUM master/manager/leader is there to guide the flow and provide support.

In agile, the manager no longer assigns specific tasks to members on a day-to-day basis. Tast assignment is coollectively decided by members of the group. The manager/SCRUM master is there to provide support and help in difficult situations: listen, explain what can be done, coach, mentor, catch errors, remove impediments, adress skepticism that might ruin team spirit, *etc.* to developers.

*Sometimes, a traditional manager is still preferred depending on the project.*

4. Maintain a sustainable pace

> Avoid extreme pressure to meet deadlines.

> The best work is done in peace, quiet, and respect.

People perform best when not overstressed. Overtime should always be accompanied with the appropriate following relaxation/break and "crunch" should be avoided.

This can most of the time be achieved by:
- frequent code merges,
- maintaining executable, test-covered, high quality code,
- constant refactoring in order to keep fresh and aler minds,
- collaborative work,
- constant testing,
- (...)

5. Produce minimal software:
    - Produce minimal functionality
      > YAGNI: You Ain't Gonna Need It
      Only code what a real customer is going to use; do not produce waste. In other words, do not waste time on what you think you are going to need and instead *focus on what is strictly needed*.

      > Only do what user stories ask for. Not more. 

      Extra features can increse complexity of the code and drive up costs non-linearly.

*Different user groups can still provide different user stories. Just because one user doesn't need a functionality, doesn't mean another is not asking for it. What is wasteful is writing code that no user story is asking for.*

***The "lean" view***
> Seven wastes of software development:
>> - Overproduction: Extra/Unused features  
>> - Inventory: Partially unreleased developed work  
>> - Extra Processing: Intermediate/Unused artifacts  
>> - Motion: Seeking (missing) Information about customer or algorithmic needs  
>> - Defects: Escaped defects not caught by tests/reviews  
>> - Waiting/Customer Waiting  
>> - Transportation: Handoffs (*e.g.* in manufacturing, it would be the transport of raw materials and finished products; in software this would be equal to several notations and tools used to work on the same thing like in UML or having to translate and communicate between multiple formalisms in a programming language)  

    - Produce only the product requested
      >  Do not **over**-worry about producing extendable software
      Start by coding the simplest thing that could work. "Ideally", it "should" stand the test of time and change by being reusable, being written in such a way that it looks beyond immediate goals or requirements. *The only way to get there is through experience or by starting from a simple code that gets the job done; the perfect solution is not just going to appear out of thin air; and the perfect solution doesn't need to be found as long as the code meets requirements.*  

    - Develop only code and test
      > Code
      > Test
      
      > Cockburn: "You get no credit for any item that does not result in running, tested code." (unless for final delivrables such as training materials and delivery documentation.)
      Do not put too much emphasis on plans or intermediate documents that will not be beneficial to and/or never be seen by the customer.

### Technical Principles 
*Comes from XP and other agile methods*

6. Develop iteratively
    - Produce frequent working iterations
    
    > * Vertically-layered clusters
    >  User Interface   ^
    >  Business Logic   |
    >  Networking       | Iterations
    >  Database         |
    A lot of time is spent at the start without producing any useful functionality.   

    >                                  UI1     UI2     UI3
    >  Horizontally-layered           Logic1  Logic2  Logic3
    >       clusters                   Net1    Net2    Net2     ...
    > ("the more agile way")           DB1     DB2     DB3
    >                                 ---------------------->
    >                                       Iterations

    Each (frequent) iteration produces a working system. Typically, an agile project uses 2 to 6 weeks as standard for adopted iterative development. It can also go down to few days or even one day, the focus should be on frequent iterations according to what is needed for the project. 

    - Freeze requirements during iterations (Closed-Window Rule)
      Addition of functionality during an iteration not defined in user stories means the cancellation of the current sprint (SCRUM).
      This helps bring order and focus to what is being worked on.
      *A sprint is interrupted and restarted only in extreme rare cases; mostly to adapt to competition.*

Alternatively:
> Dual development (mixed Agile/non-agile): build infrastructure early on and later produce releases while respecting release dates with respect to getting working code to the user.

7. Treat tests as a key resource:
    - Do not start any new development until all tests pass
    *concept of Regression test suite*
    It is forbidden to start adding new functionality until we are sure that all existing tests pass; all the existing functionality is reasonable well-implemented as guaranteed (or at least supported).

    *in some cases, some tests might be considered currently non essential and might not require passing testing before moving on* 
    
    - Test first

    - (TFD: Test First Development; TDD: Test-Driven Development)

8. Express requirements through scenarios/user stories

    User story: something the user wants. *e.g.* change tax calculations on invoices

    Standard form:
    > "As a <user_or_role>
    > I want <business_functionality>
    > so that <business_justification>
    
    Example:
    > "As a _customer_, I want _to see a list of my recent orders_, so that _I can track my purchases with a company_."

    > "As a _registered user_, I want to _log in_, so I can _access subscriber content_.

    User stories are generated on-the-go before every sprint. They provide a good description of how the system needs to perform in a typical scenario.

    *There are many ways to accomplish something, hence the need for abstraction in user stories. For example, 2*2 = 4, 3*3=9 or 2^2 = 4 3^2 = 9 , but also 2+1^1+0 = 4 or 3+2^2+1 = 9.*

### Method-Specific Principles


## Roles

## Practices

## Artifacts

## Agile Methods/Methodologies
*  Extreme Programming (**XP**)
Response to UML (Unified Modelling Language) and CMMI (Capability Maturity Model Integration) etc. that emphasize process and documentation; but **what matters is the program and programming**

*  **Lean** Software
Made for engineering fields, especially the car industry. **Get rid of waste** (ex. useless documentation, ...); **concentrate on what is delivered to customer**

*  **Crystal** Methodology
Set of methods with various degrees of importance to process

*  **SCRUM** (most widely adopted)
Management method emphasizing ideas via **self-organising teams** (compared to closely managed one) and short release interations (**Sprints**)

*  (...)

 
