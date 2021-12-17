# Agile Software Development

## Why and How

### Waterfall **Model**
* Royce (1970)
<pre>
    System      -->    Software    -->  Analysis  -->  Program  -->  Coding  -->  Testing  -->  Operations  
 Requirements   <--  Requirements  <--            <--  Design   <--          <--           <--
</pre>

* Updated/Modern
<pre>
 Feasibility  -->  Requirements  -->  Specification  -->  Global  -->  Detailed  --> Implementation --> V & V --> Distribution   
   Study      <--                <--                 <--  Design  <--   Design   <--                <--       <--
</pre>

Drawbacks/Inconveniences:
* Late appearance of code: Code provides a more direct feedback for feasibility and often times problems appear only when coding
* Doesn't take into consideration changes during steps
* Maintenance is not taken into account
* Division of labor hampering Total Quality Management
* Impedance mismatches between analysis, design, and implementation (due to reliance on intermediary documents)
* Highly synchronous model

**Agile** adresses the above problems while also rejecting the problem-prone upfront requirements phase (**requirements change** over time; so the time spent **formalising** requirements should be minimised). This also reduces waste (Lean) because of requirements not being met. **Agile replaces requirements with user stories.**

Some concrete examples of how agile methodologies address these issues:
* Beck (XP): Requirements gathering is an activity that provides details just before it is needed in development.  
* Cohn (SCRUM): All work occurs within the repeated cycle of sprints with the absence of upfront analysis or design phase.  
* Poppendieck (Lean): Requirements should be more aptly called candidate solutions and not set in stone. "separating requirements from implementation is just another form of handover" 

## Manifesto (2001)
> <agilemanifesto.org>

```
   Individuals and Interactions     >        Processes and Tools
        Working Software            >     Comprehensive Documentation
      Customer Collaboration        >       Contract Negotiation
       Responding to Change         >         Following a Plan
```

## The 12 Agile Principles (*not verbatim*) and Agile Values:
*  **New and reduced role for manager**  
No assignment of tasks to project members by project manager. The team self-organises itself instead.

> 5. Build projects around motivated individuals giving them the **environment, support, and trust** they need.  

> 11. **Do not over-manage developers**; the best architectures, requirements, and designs emerge from self-organizing teams.

*  **No "Big Upfront" steps**  
Coding to produce software starts right away. Design and re-evaluation of requirements are done continuously during the coding process instead of being fixed from the start.

> 1. Highest priority is to **satisfy customer** through **early and continuous delivery** of valuable software.  

> 3. Deliver working software frequently; give preference to **shorter timescales**.

*  **Iterative development**  
Project members communicate on a regular basis in a more progressive way. For *e.g.*, every day, or every few days, or every few weeks depending on the scope of the project. *i.e.*, development cycles should last from one day to a few weeks requiring each cycle to have elicitation, design, development, and testing on a usually limited scope.

> 2. Welcome changing requirements, *even late in development*. The **ability to change gives competitive advantage**.  

> 4. Business people and developers should **work together**.  

> 6. **Face-to-face conversation** is the most efficient and effective way for conveying information.  

> 8. Promote sustainable development: **maintaining constant pace** while avoiding "crunch"  

> 12. Communicate to **reflect on successes and failures** in order to **adjust team behaviour accordingly**.

*  **Limited, negotiated scope**  
System does exactly what's needed, *i.e.* build functionality that is strictly needed; this reduces waste (both virtual and physical).

**Negotiator Scope**  
> [Beck, 2005] Extreme Programming Explained by Kent Beck, Cynthia Andres  
>  
>> Write contracts for software development that fix time, costs, and quality but call for **ongoing negotiation** of the precise scope of the system. Reduce risk by signing a **sequence of short contracts** instead of one long one.
>  
>> You can move in the direction of negotiated scope. Big, long contracts can be split in half or thirds, with the optional part to be exercised only if both parties agree. Contracts with high costs for change requests can be written with less scope fixed up front and lower costs for changes.
>  
> In other words, ("blind") commitment to both delivery date and a specific set of functionalities do not mix well. Sometimes focusing on delivery date while forgoing some functionalities is needed; while other times delivery date needs to be flexible in favour of a certain set of functionalities. 

> 10. Simplicity -the art of maximising the amount of work not done- is essential; **write simple code** as much as you can. *More appropriately and realistic, do not leave your code complicated, make it simple, easy to read, and accessible (anyone can understand) to everyone as much as you can once it behaves as desired.*

* **Focus on quality achieved through testing**  
Testing makes for better quality products.

> 7. (Tested) **Working software** is the **primary measure of progress**.  

> 9. **Continuous attention** to technical excellence and good design enhances agility.

## Updated Principles

Over the years, this has given rise to multiple agile methodologies and the corresponding update to the agile principles to adress issues or fill in the gaps.

### Agile Methods/Methodologies
Some of the most popular agile methods are:

*  Extreme Programming (**XP**)
Response to UML (Unified Modelling Language) and CMMI (Capability Maturity Model Integration) etc. that emphasize process and documentation; but **what matters is the program and programming**

*  **Lean** Software
Made for engineering fields, especially the car industry. **Get rid of waste** (ex. useless documentation, ...); **concentrate on what is delivered to customer**

*  **Crystal** Methodology
Set of methods with various degrees of importance to process

*  **SCRUM** (most widely adopted)
Management method emphasizing ideas via **self-organising teams** (compared to closely managed one) and short release interations (**Sprints**)

*  (...)

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
    Regression test suite: A collection of tests including tests that failed in the history of the project, to make sure that faults that already occured in the past do not occur again when implementing new features

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
* **Everything not adding value to the customer is considered waste** [Lean]
This includes: unnecessary code, unnecessary functionality, delay in progress, unclear requirements, insufficient testing, avoidable process repetition, bureaucracy, slow internal communication, partially done coding, waiting for other activities/team/processes, defects/lower quality, managerial overhead, ...

*Value stream mapping: strategy to recognize waste. Eliminate it iteratively*

* **Amplify learning** [Lean]
  * Run tests as soon as the code is written to prevent accumulation of defects
  * Try different ideas by writing, testing code, and building instead of added documentation or planning
  * Get user input, for example by providing screenshots of the product in development or setting up feedback sessions with customers
  * Enforce short iteration cycles, each including refactoring and integration testing. This maintains a steady supply of feedback as we go

> Multiple design approach [Lean]: assigning the sale problem to different teams, in parallel (*comment: and this is not wasteful!?*)

* **Decide as late as possible** [Lean]
  * Keep decisions pending until they can be made on facts (customer needs/feedback) instead of assuming, as much as possible
  * The more complex a system is, the more if can be able to adapt and change to need
  * Use iterative approaches to adapt to changes and correct mistakes. This reduces cost quite a bit by avoiding to have to correct mistakes after release
  * Planning should be used to concentrate on different options, adapting to the current situation, and clearing up confusions by establishing patterns so they can be adressed quickly and effectively

* **Focus** [Crystal]
In order to ensure continuous progress, focus on an individual task instead of getting scattered amongst multiple tasks.
Avoid interruptions as much as possible when focusing on one task.
Avoid switching projects or (big?) tasks too rapidly (at least 2 days before switching) 

Clearly define and prioritise goals so the project can advance in the asme direction smoothly

* **Deliver as fast as possible** [Lean, SCRUM]
> It is not the biggest that survives, but the fastest. [Poppendieck]

The sooner the end product is delivered, the quicker feed back is received and incorporated in the next iteration.
For software, the Just-In-Time production ideology means presenting the needed result and letting the team organise itself to obtain it in a specific iteration.

> This is not always true, for example VisiCalc opened up the market for spreadsheets only to get dwarfed by bigger companies right after.

* **Minimise dependencies** [SCRUM]
"Scrum asserts that it is possible to remove dependencies between user stories, so that at any point any user story can be selected from a queue according to the proper criteria (maximising business value)"

*In reality, the complexity of a software can easily make it such that the various features are so intricately intertwined that it's difficult to remove anything without everything else crumbling down*

* **Adding features** [*Zave*]
"
In telecommunication software, feature interactions are a notorious source of runaway complexity, bugs, cost and schedule overruns, and unfortunate user experiences.

Bob has "call-forwarding" enabled and is forwarding calls to Carol. Carol has "do-not-disturb".
Alice calls Bob, the call is forwarded to Carol, and Carol's phone rings because "do-not-disturb" is not applied to a forwarded call.

Alice calls a sales group. A feature for the sales group selects Bob as a sales representative on duty, and forwards the call to Bob. Bob's cellphone is off, so his personal Voice Mail answers the call and offers to take a message.

(...more examples...)
"

**Imagined User Stories** [Bertrand Meyer, ETHx course on EDX] corresponding to previous example:
> As an executive, I want a redirection option so that is my hpone is busy the call is redirected to my secretary  
> As a systems configurator, I want to be able to specify various priorities for "busy" actions  
> As a salesperson, I want to make sure that is a prospect calls while I am in a conversation, the conversation is interrupted so that I can take the call immediately  
> As a considerate correspondent, I want to make sure that if a call comes while my phone is busy I get to the option of calling back as soon as the current call is over

* **Personal Safety** [Crystal]
  * Encourage free expression of ideas
  * Do not ridicule anyone because of a question or suggestion
  * Build trust within the team

* **Humanity** [XP]
Recognise that software is developed by people

Offer developers what they expect: saftey, accomplishment, belonging, growth, intimacy

## Roles
### Traditional Manager Roles
* Define goals
* Define deadlines
* Assign tasks
* Provide interface with higher management
* Provide interface with customer
* Validate requirements
* Decide whether goals have been met
* Enfor deadlines
* Coach, mentor
* Enforce rules and methodology
* (...)

> A manager can be a software professional, but also not, for example someone with an MBA and no software knowledge

### The 3 SCRUM Roles
1. (self-organising) team
*group of 7 +/- 2 members*
The team:
* is cross-functional *(one person does not own a whole area, anyone can take on any task)*
* selects iteration(/sprint) goal and work results
* organizes itself and its work
* can do everything within guideline to reach goal
*  demos work results to product owner

> scrums of scrums for bigger projects that need more members

**core participants and fellow travelers**
Core participants are committed to the project; fellow travelers are involved in the project. Fellow travelers stand on the side in discussions and give their opinion if invited to do so.
This is done so meetings are kept focused.

2. Product Owner
*person*
* defines product features
* decides on release date
* decides on release content
* responsible for product profitability (ROI)
* prioritises features according to market value
* can change features and priority over 30 days
* accepts or rejects work results

> is not in charge of individual small sprints

3. Scrum Master
*person*
* ensures that the team is functional and productive
* enables cooperation across all roles and functions
* shields team from external interferences
* enforces process: daily meeting, planning and review meetings
* **removes impediments**
* normally, does no development

> **Impediment**
> Anything that affects the velocity (progress) of the team. [Lean]
>
> Examples:
> * Hardware limitations
> * Missing requirements
> * Missing supporting software (wheter from within or outside of the team)
> * Management interference
> * Bureaucratic delays

*A SCRUM Master can be in several projects if they have the time to if they do not develop.*

**Managers in Agile (if any)**
Agile Managers:
* support team in its use of SCRUM
* contribute wisdom, expertise, and assistance
* Do not "play nanny":
  Assign tasks, get status reports, and other forms of micromanagement
* instead, "play guru":
  Mentor, coach, devil's advocate, help remove impediments, and solve problems
* may need to evolve their management style, *e.g.* use Socratic questioning to help team discover solutions (rather than imposing a solution)

### Other Agile roles
- Expert User [Crystal]
Allows the obtention of actual and accurate needs from actual users
  * Should be an actual user (not just a tester from the development team)
  * Has expert knowledge of the project area
  * Answers questions
  * Suggests solutions to problems
Crystal advises a 2-hour meeting a minimum once per week with the ability to make phone calls

- Customer [XP]
The customer:
  * provides precise stories allowing developers to produce comprehensive task cards and accurate estimates
  * weighs stories against each other and analyzes risk correctly, choosing stories of maximum value for the next iteration
  * trusts developer's technical decisions
  * works within the team in order to quickly provide accurate on-the-go guidance and feedback

- Developer [XP, SCRUM]
**Turns customer stories into working code**

> Frequently asks himself "How to implement it?", "How long will it take?", "What are the risks?

Obligations:
* Works with customer to understand the stories
* Decides implementation from a story
* Estimate work for each story, based on implementation decisions and experience
* Knows and understands technical issues
* Creates and maintains the system as it evolves
* Identify features that depend on other features
* Identify risky features and reports them to customer
* Follows team guidelines
* Implements only what is necessary
* Communicates with customer constantly

Rights (?):
* Estimates own work
* Works sensibly and schedules only work that can be done (so the schedule is predictable)
* Focuses on testing, refactoring, and customer comunication to produce code that meets customer's needs
* Allows the customer to make *business decisions*

- Tracker [XP, SCRUM]
Keeps track of the schedule by monitoring progress and rate of progress in order to determine if the iteration is on schedule. This is done by asking each developer how many tasks they have completed every few days

> Velocity: ratio of ideal time estimated for tasts to actual time spent implementing them

Keeps in mind:
* changes in velocity
* amount of overtime worked
* ratio of passing to failing tests

- Coach [XP]
*Optional role*

The coach:
* guides and mentors the team
* leads by example
* teaches when necessary (even if it's by doing)
* may offer ideas to solve thorny problems
* may serve as intermediary with management

*In SCRUM, this role is absorbed into SCRUM Master.*

## Practices

### Meetings
*model were created for classical teams, could be adapted to distributed teams with modern forms of work (teleworking for example)*

Specific regular "ritual" meetings
* Daily Meeting (most important)
Short (usually 15 minutes), held every working day, should be one of the first things in the work day.
Precise and to-the-point, defines commitments and identify/uncover impediments ("deep" resolutions take place outside of this meeting)
Committed members:
  * What did you do yesterday?
  * What will you do today?
  * Are there any impediments in your way?

* Planning Meeting
Done at the beggining of every sprint (individual iteration)
Goal: define work for the sprint.
Outcome: Sprint Backlog, with time estimate for every task

8-hour time limit (typically one work day):
1st half: product owner + team: prioritize product backlog
2nd half: team only: plan for Sprint, producing sprint backlog

* Retrospective Meeting
*Internal team meeting*
To reflect on past sprint in order to make continuous process improvements
  * What went well?
  * What could be improved?

3-hour time limit

* Review Meeting
To review completed and incomplete work

Present and demo completed work to stakeholders
Incomplete work cannot be demonstrated

4-hour time limit

> Reflective improvement (Crystal)  
> Developers must take breaks from regular development to look for ways to improve the process  
> Iterations help with this by providing feedback on whether or not the current process is working  

### Development
```
* Pair Programming [XP]
*best known, controversial (Kent Beck, originator of XP said this should be default)*
*not desirable as sole technique for developping software*

Two programmers sitting at one machine; thinking out loud
Goals:
  * Make thinking process explicit
  * Keep each other on task
  * Brainstorm refinements to system
  * Clarify ideas
  * Take initiative when other stuck, lowering frustration
  * Hold each other accountable to team practices

*everything is explicit, discussed, explained before being entered into code; sometimes just trying to explain points out inconsistencies or problems that could arise*

*studies have shown that pair programming results in the same amount of productivity and quality as traditional quality-oriented techniques like code review; however pair programming still shines in tricky cases*

> Pair programming is not mentoring. The pair should be at approximately equal levels of competence.

* Single code base [XP]
Maintain a single code base: avoid branching (even if permitted by configuration management system)

* Shared code [XP]
Code responsibility is shared by entire team, no one person owns any piece of code. Permission to change code should be available to everyone on the same team/project.

Rationale:
  * most non-trivial features extend across many layers in the application
  * code ownership creates unnecessary dependencies between team members and delays
  * what counts is implemented features, not personal responsibility
  * avoid blame game
  * avoid specialisation
  * minimise risk (team members leaving)

* Leave optimisation till last [XP]
Wait until you have finished a story and run your tests so you have a working code before trying to optimise the code

Only by having a working code can you know what needs to be optimised

Trying to anticipate problems before they exist is wasteful

* Simple design [XP]
Produce the simplest design that works

Refactor (improve design efforts) as needed

* Incremental design [XP]
Developers work in small steps, validating each before moving to the next

Three parts:
  * Start by creating the simplest design that could possibly work
  * Incrementally add to it as the needs of the software evolve
  * Continuously improve design by reflecting on its strengths and weaknesses

> "When you first create a design element, be completely specific. Create a simple design that solves only the problem you face, no matter how easy it may seem to solve more general problems."

> "The ability to think in abstractions is often a sign of a good programmer. Coding for one specific scenario will seem strange, even unprofessional. Waiting to create abstractions will enable you to create designs that are simple and powerful. Do it anyway."

*abstraction and weeding out problems before they even arise are skills a good engineer should have, "take" this design with caution*

* System Metaphor [XP]
"A metaphor is meant to be agreed upon by all members of a project as a means of simply explaining the purpose of the project and thus guide the structure of the architecture"

Benefits:
  * Communication, including between customers and developers
  * Clarify project, explain functionality
  * Favors simple design
  * Helps find common vocabulary

* Refactoring (XP)
"Disciplined technique for restructuring an existing body of code, altering its internal structure without changing its external behaviour"

Examples:
  * Encapsulate attribute (field) into function
  * Replace conditional with more object-oriented technique of polymorphism and dynamic binding
  * Extract routine (method), *i.e.* remove duplication where possible
  * Rename routine or attribute
  * Move routine or attribute to another class
  * Pull up, pull down in the inheritance hierarchy

used in agile methods as a substitute for upfront design
```

### Release 
```
Early and often
Agile encourages frequent integration, deployment, release

**Only one pair integrates code at a time** [XP]
collective code ownership; development proceeds in parallel

but: to avoid conflicts, only one pair is permitted to integrate its change at any given time

**Continuous integration** [XP]
the combination of frequent releases with relentless testing

keep system fully integrated at all times

rather than weekly or daily builds, build system several times per day
benefits:
* integration is easier because little has changed
* team learns more quickly
* unexpected interactions rooted out early: conflicts are found while team can still change approach
* problematic code more likely to be fixed because more eyes see it sooner
* duplication easier to eliminate because visible sooner

> *release early and often*  
> follows from rejection of "Big Upfront Design"  
> Avoid long architectural phases  
> Refactor

**small releases** [XP]
XP teams practice small releases in 2 important ways:
* release running, tested software, delivering business value chosen by the Customer, every iteration. The Customer can use this software for any purpose, whether evaluation or even release to end users
* release to end users frequently as well. Web projects release as often as daily, in house projects monthly or more frequently. Ven shrink-wrapped products are shipped as often as quarterly.

**Incremental deployment** [XP, SCRUM]
deploy functionality gradually

"Big Bang" deployment is risky

*not always applicable, for example, to release the Euro all ATMs had to be ready for it from Day One*

**daily deployment** [XP]
goes back to Microsoft's Daily Build
"China Shop Rules": you break it, you fix it (the dev who made the code, has to fix the code themselves)

difficult to reconcile with other XP principle

**Ten-minute build** [XP]
"Make sure that the build can be completed, through an automatic script, in ten minutes or less, to allow frequent integration. Includes:
* compile source code
* run tests
* configure registry settings
* initialize database schemas
* set up web servers
* launch processes
* build installers
* deploy
Make sure the build provides a clear indication of success or failure"

"If it has to take more than ten minutes, split the project into subprojects, and replace end-to-end functional tests by unit tests"

**Weekly cycle** [XP]
Plan work a week at a time. Have a meeting at the beginning of every week:
1. review progress, including how acutla progress for the previous week matched expected progress
2. have customers pick a wekk's worth of stories to implement this week
3. break the stories into tasks

Start week by writing automated tests that will run when the stories are completed. Spend rest completing stories and getting tests to pass. The goal is to have deployable software at the end of the week.

The nice thing about a week is that everyone is focused on having the tests run on Friday. If you get to Wednesday and it is clear that all the tests won't be running, you still have time to choose the most valuable stories and complete them.

```

### Testing and Quality

```
**Coding standards** [XP]
project members all code to the same conventions

**All codes must have unit tests** [XP]
*widely adopted*
Core idea of XP:
"Do not write code without associate unit tests"

**all code must pass unit tests before moving on** [XP]
code that does not pass tests is waste

Do not proceed to next step, *e.g.* next user story or next release, until all tests pass

*if a test is not important, it's better to remove it and the corresponding functionality*

**Test-First Development** [XP]
Write tests before code

The test replaces the specification

**Code the unit test first** [XP]
"Here is a really good way to develop new functionality:
1. Find out what you have to do.
2. Write a UnitTest for the desired new capability. Pick the smallest increment of new capability you can think of.
3. Run the UnitTest. If it succeeds, you're done; go to step 1, or if you are completely finished, go home.
4. Fix the immediate problem: maybe it's the fact that you didn't write the new method yet. Maybe the method doesn't quite work. Fix whatever it is. Go to Step 3.
**A key aspect of this process: don't try to implement two things at a time, don't try to fix two things at a time. Just do one.**
When you get this right, development turns into a very pleasant cycle of testing, seeing a simple thing to fix, fixing it, testing, getting positive feedback all the way. Guaranteed flow. And you go so fast!

Try it, you'll like it."

this can be generalised in:
**Test-Driven Development**
Standard cycle:
* Add a test
* Run all tests and see if the new one fails
* Write some code
* Run the automated tests and see them succeed
* refactor code
Expected benefits:
* catch bugs early
* write more tests
* drive the design of the program
* replace specifications by tests
* use debugger less
* more modular code
* better coverage
* improve overall productivity

The basic idea is sound... ... but not the replacement of specifications by test

Major benefit: keep an up-to-date collection of regression tests

Requirement that all tests pass can be unrealistic (tests degrade, a non-passing test can be a problem with the test and not with the software)

Basic TDD idea can be applied with specifications! See Contract-Driven Development

**when bug found, create test before fixing it** [XP]
> "A bug is not an error in logic, it is a test you forgot to write"

**Root-cause analysis** [XP, SCRUM]

When finding a defect, do not just fix it but analyse cause and make sure to correct that cause, not just the symptom

this makes sure it doesn't happen again

**Run acceptance tests often and puclish results** [XP]

Acceptance tests are black box system tests. Each acceptance test represents some expected result from the system

Automate them so they can be run often

Publish acceptance test score to the team so everyone knows what is going on
```

### Management (and others)

```
**Scrum of scrums** [SCRUM]
*to address beyond 7 +/2 teams*
Each day after daily scrum
CLuster of teams discuss areas of overlap and integration
A designated person from each team attends
Agenda as Daily Scrum, plus the following four questions:
* What has your team done since we last met?
* What will your team do before we meet again?
* Is anything slowing your team down?
* Are you about to put something in another team's way? (anticipate impediments)

**Whole team** [XP, SCRUM]
All contributors sit together as members of one team:
* includes a business representative who rpovides requirements, sets priorities and steers the project
* included programmers
* may include testers
* may include analysts, helping to define requirements
* often includes a coach
* may include a manager
None of these roles is the exclusive property of just one individual. The best teams have no specialists, only general contributors with special skills

*this is to have various stakeholder categories in the same place: devs, customers, ...

**Planning poker** [SCRUM]
* present individual stories for estimation
* discuss
* Deck has successive numbers (quasi-Fibonacci)
* Each participant chooses estimate from his deck
* Keep estimates private until everyone has chosen a card
* reveal estimates
* repeat until consensus

(Variant of Wideband Delphi technique.)

*loud talkers might "_impose_" their estimate...influencing others; not the best option, but necessary*

**Open workspace** [XP, Crystal]
Workspace:
* organised around pairing stations
* with whiteboard space
* locating people according to conversations they should overhear
* with room for personal effects
* with a place for private conversations

expected benefits: improve communication, resolve problems quickly with the benefits of face-to-face interaction (as opposed to e.g. email)

*good idea to use with XP, especially if lots of whiteboard space*

*not best, some code better with less communication*

**osmotic communication** [Crystal]

Team is together in a room and listen to each other
Information to flow around it
Developer must break concentration if necessary
Information flows quickly throughout team
Questions answered rapidly
All team updated on what is happening
Reduce need for email and other non-direct communication
Facilitate taking over of others' tasks

**informative workspace** [XP, SCRUM]
Facilitate communication through well-organised workspace:
* story board with user story cards movable from not started to in progress to done column
* release charts
* iteration burndown charts
* automated indicators showing the status of the latest unit-testing run
* meeting room with visible charts, whiteboards and flipcharts

*seeing the progress made or being made helps with motivation*

**technical environment** [Crystal]
*give devs the tools that they need, don't skimp on things like memory, give them the tools they need to be effective in software development*
access to automated test, configuration management, frequent integration, code repository

**team continuity** [XP]
keep the team together and stable

do not reassign people to other teas or treat them as mere resources

**shrinking teams** [XP]
*controversial*
as a team grows in capability, keep its workload constant but gradually reduce its size
this frees people to form more teams
when the team has too few members, merge it with another too-small team
*not very practical*

**code and tests** [XP]
Maintain only code and tests as permanent artifacts
*somewhat extreme*

**Customer always available** [XP]
*embedded customer*
All project phases require communication with customer, preferably face to face. Assign one or more customers to the development team who:
* help write user stories to allow time estimates & assign priority
* help make sure most of the desired functionality is covered by stories
* during planning meeting, negotiate selection of user stories for release
* negotiate release timing
* make decisions that affect their business goals
* try system early to provide feedback
* (etc.)

"This may seem like a lot of the customer's time but the customer's time is saved initially by not requiring a detailed requirelents specification and later by not delivering an uncooperative system"

**Slack** [XP]
"in any plan, include some minor tasks that can be dropped if you get behind."

goals:
* establish trust in the team's ability to deliver
* reduce waste

*not many companies apply this*

*in general, don't plan too tight, don't plan every second of your workday, leave some room*
```

## Artifacts

### From user stories to burndown charts

Virtual/intellectual artifacts, physical artifacts (to support virtual artifacts)
here, we mix both

* User story [XP,SCRUM]
defines an atom of functionality (see practices)

* Story card [XP]
to express user stories
EXAMPLE
*can be done in software tools*

* Task card [XP]
for implementing an iteration, defines number of tasks

* Use case
*used outside agile too, for example one of UML diagram types*
describes how to achieve single business goal or task through the interactions between external actors and system

use case v/s user story: (both describe the interaction of a user with the system) see previous line

use case example:
e.g.online customer can view products, purchase products > payment processing system, etc.
EXAMPLE

> "Think of a user story as a use case at 2 bits of precision"

User story:
* very simple
* written by customer
* incomplete, possibly innacurate
* does not handle exceptional cases
* starting point for additional discussions with customer

Use case:
* more complex
* written by developer in cooperation with customer
* attempts to be complete, accurate
* should handle all possible cases
* intended to answer any developer questions about customer requirement without further interaction with customer

a user story is a starting point for additional discussions with the customer, while a use case typically does not require further interaction with the customer

* Product backlog [SCRUM]
  * maintained throughout project
  * property of product owner
  * open and editable by anyone
  * contains backlog items: broad descriptions of all potential features, prioritized by business value
  * includes estimates of business value
  * includes estimates of development effort, set by team

Visualised in "task board" (next)

* Task Board, Story Board [SCRUM]
visual representation of backlog
EXAMPLE
used to see and change the state of the tasks of the current sprint: "to do", "in progress", "done".

benefits:
- transparency
- collaboration
- prioritization
- focus
- self-organisation
- empiricism (decision making based on actual progress)
- "humility"
- morale

* velocity [SCRUM]
measure (numerically) of progress in a project:
  number of items delivered
  
  can be:
  * measures in tasks, user stories, backlog items, ...

how to keep track:
* burndown chart
publicly displayed chart, updated ervy day, showing, for the sprint backlog:
- remaining work
- progress
EXAMPLE
x = days
y = remaining tasks

blue line: if constant velocity

curve goes up if tasks are added (so it shows also how much unanticipated tasks arose)

shows both progress and the remaining work in terms of velocity

* bullpen [XP]
single, open room
(see "informative workspace" principle)

where people work
everyone can interact with anyone

## Assessment of agile methods
assessment is needed to ascertain what of all the ideas are right and not right for your project and team

**ugly** (harmful, not recommended):
* rejection of upfront tasks
  * particularly: no upfront requirements
  * dismissal of a priori architecture work
* user stories as a replacement for abstract requirements (user stories are too specific, describing individual interactions with the system)
* tests as a replacement for specifications
* feature-based development and ignorance of dependencies
* method keeper (e.g. Scrum Master) as a separate role
* test-driven development (but not the rest of agile's emphasis on tests)
* dismissal of traditional manager tasks
* dismissal of auxiliairy products and non-shippable artifcats (ludite rule; some extra things DO need to be coded)
* dismissal of a priori concern for extensibility
* dismissal of a priori concern for reusability

*analysis paralysis?*

dual development good; AT SOME POINT stop looking at the problem and jump into the solution

going into code directly can be harmful; some time is needed to analyse the problem before coding

user stories validate requirements, not replace them

scrum master should code too



**hype/the indifferent**: (just hyped... result may vary/not be of much help)
* pair programming (good only in select cases)
* open-space working arrangements (can be as destructive as beneficial if people don't get along together)
* self-organising teams
* maintaining a sustainable pace (sometimes the customer just wants a big delivery/release)
* producing minimal functionality
* planning poker
* cross-functional teams (inevitable that some people are expert in an area)
* embedded customer (scrum product owner is a more realistic idea)

**good** (show to be highly beneficial by studies):
* acceptance of change (embrace the soft in software)
* iterative development
* emphasis on working code
* tests as one of the key resources of the project
* constant test regression analysis
* notion of velocity (actual real numerical measure of the progress of the project)
* no branching
* product (but not user stories!) burndown chart
* daily meeting

**brilliant**
* short iterations
* closed-window rule (helps with the natural phenomenon of filtering and attrition especially when coupled with short iterations)
* refactoring (but not as a substitute for design)
* associating a test with every piece of functionality
* continuous integration

**Final observations**

software development is hard; quality is key

lots of good ideas can help; there is no reason to reject those from a particular style of software engineering
  * particularly in the absence of credible empirical data

agile can complement and can be complemented

Agile will find its place in the history of productive software engineering ideas

agile is a major step in the evolution of software engineering

