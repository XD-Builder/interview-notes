## Interview Process

### Interviewer makes an assessment of your performance

1. Analytical skills - Did you need much help solving the problem and how optimal was your solution and the time it takes. If it's a design question, did you structure the problem well and think through the tradeoffs of different decisions?
2. Coding skills - Were you able to successfully translate your algorithm to reasonable code? Was it clean and well-organized? What about edge cases and did you use good style?
3. Technical knowledge/ Computer Science fundamentals - Do you have a strong foundation in CS and the relevant technologies?
4. Experience - Have you made good technical decisions in the past? Have you built interesting, challenging projects? Have you shown drive, initiative, and other important factors?
5. Culture fit/communication skills - Do your personality and values fit with the company and team? Did you communicate well with your interviewer?

### Reasoning for this interviewer assessment process?

1. False negatives are acceptable
2. Problem-solving skills are valuable - if you're able to work through several hard problems, you're probably pretty good at developing optimal algorithms. You are smart and smart people tend to good things that are valuable at a company.
3. Basic data structure and algorithm knowledge is useful - Understanding trees, graphs, lists, sorting, and other knowledge does come up periodically and it's really valuable when it does. In addition, the majority of problem-solving questions involve some of the CS basics.
4. Whiteboards let you focus on what matters.

## Behind the Scenes

### General Process

1. Once you are selected for an interview, you usually go through a screening interview conducted over the phone. Top schools candidate may have these in-person.
   1. "Screening" interview often involves coding and algorithm questions, and the bar can be just as high as it is for in-person interviews.
   2. Typically one or two screening interviews before being brought on-site
2. On-site interview round usually have 3 to 6 in-person interviews.
   1. One of these is often over lunch which is usually not technical, and the interviewer may not even submit feedback. This is a good time to discuss your interests with and to ask about the company culture.
   2. Your other interviews will be mostly technical and will involve a combination of coding, algorithm, design/architecture, and behavioral/experience questions.
   3. After your interview, your interviewers will provide feedback in some form. In some companies, your interviewers meet together to discuss your performance and come to a decision while in others each interviewer submits a recommendation to a hiring manager or hiring committee to make a final decision.
3. Most companies get back after about a week with next steps (offer, rejection, further interviews, or just an update on the process).
4. After waiting more than a week, you should follow up with your recruiter. No response from recruiter means nothing and the intention is that all recruiter should tell candidates once a final decision is made.

### Facebook Interview Process

1. Once selected for an interview, candidates will generally do one or two phone screens which will be technical and involve coding.
2. After the phone interviews, you might be asked to do a homework assignment that will include a mix of coding and algorithms. Pay attention to your coding style here.
3. During your on-site interview, you will interview primarily with other software engineers, but hiring managers are also involved whenever they are available. All interviewers have gone through comprehensive interview training, and who you interview with has no bearing on your odds of getting an offer.
4. Each interviewer is given a "role" during the on-site interviews, which helps ensure that there are no repetitive questions and that they get a holistic picture of a candidate. These roles are:
   1. Behavioral, "jedi" - This interview assess your ability to be successful in Facebook's environment. Would you fit well with the culture and values? What are you excited about? How do you tackle challenges? Be prepared to talk about your interest in Facebook as well. Facebook wants passionate people.
   2. Coding and Algorithms, "Ninja" - These are your standard coding and algorithms questions.
   3. Design/Architecture, "pirate" - Openly discuss different solutions and their tradeoffs.
5. Facebook wants developers with an entrepreneurial spirit so you should show that you love to build stuff fast. They want to know you can hack together an elegant and scalable solution using any language of choice.
   1. Note Facebook interviews developers for the company "in general", not for a specific team. If you are hired, you will go through a six-week "bootcamp" which will help ramp you up in the massive code base. You will get mentorship from senior devs, learn best practices, and ultimately, get a greater flexibility in choosing a project than if you were assigned to a project in your interview.

## Interview Prep

### Behavioral Questions

1. Prepare a list of projects that you have worked on and be ready to explain challenges, mistakes/failures, leadership, conflicts and what's you have done right and what you will do differently.
2. What are your weakness?
   1. Give a real weakness and how you work hard to overcome it or use it to your advantage
3. What questions should you ask the interviewer?
   1. Genuine Questions
      1. What is the ratio of testers to developers to program managers? What is the interaction like? How does project planning happen on the team?
      2. What brought you to this company? What has been most challenging for you?
   1. Insightful Questions
      1. I noticed that you use technology X. How do you handle problem Y?
      2. Why did the product choose to use the X protocol over Y protocol?
   1. Passion Questions
      1. I'm very interested in scalability and I'd love to learn more about it. What opportunities are there at this company to learn about this?
      2. I'm not familiar with technology X but it sounds like a very interesting solution. Could you tell me a bit more about how it works?
4. Know your technical projects
   1. The project had challenging components
   2. You played a central role (ideally on the challenging components).
   3. You can talk at technical depth.
5. Responding to Behavior Questions
   1. Aspects
      1. Be specific, not arrogant
      2. Limit details
      3. Focus on yourself, not your team
      4. Give structured answer
      5. SAR
         1. Situation, action and result
   2. Show initiatives, leadership, empathy, compassion, humility, teamwork/helpfulness.

### System Design and Scalability Interview

1. What is?
   1. Scalability questions are among the easiest questions. What trips up many people is that they believe there's something "magic" to those problems.
   2. These questions are simply designed to see how you would perform in real world if you were asked by your manager to design some system. Therefore, you should approach these problems as you would at work. Engage with interviewer and discuss tradeoffs.
   3. It's much more about the process you take. There are good solutions and bad solutions and there is no perfect solutions.
2. How to respond to questions
   1. **Communication** - The purpose of System Design is to evaluate your ability to communicate and stay engaged with the interviewers, how you ask questions and open about the issues of your system.
   2. Go broad first - Don't dive straight into the algorithm part or get excessively focused on one part.
   3. Use whiteboard - Helps your interviewer follow your proposed design.
   4. Acknowledge interviewer concerns - Validate interviewer's concern and make changes accordingly
   5. Be careful about assumptions - An incorrect assumption can dramatically change the problem. Ex. If your system produces analytics/statistics for a dataset, it matters whether those analytics must be in real time.
   6. State your assumptions explicitly - it allows interviewer to correct you if you're mistaken.
   7. Estimate when necessary - If you don't have the data you need, you should try to estimate/derive it from other data sources you already know.
   8. Drive - You should stay in the driver's seat and drive the entire design. Ask questions. Be open about tradeoffs. Continue to go deeper make improvements.
3. Design: Step-By-Step
   1. High level
      1. If your manager asked you to design a TinyURL system, you probably wouldn't just say "Okay" and then lock yourself in office to design it yourself. You would probably have a lot more questions before you do it. This is the way you should handle it in an interview.
   2. Step 1 Scope the problem
