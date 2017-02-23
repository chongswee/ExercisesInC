GOH CHONG SWEE
REFLECTION 2 

Self Reflection

	Teamwork:
Throughout the last sprint, there was some improvement of cordination within the group. We work
in pairs, and share a common form of communication (through slack) and have a few skype meetings to 
coordinate work. We have also make better use of the trello board, by adding clearly defined and relevant
tasks that will help us achieve our end goal for the project. All of us also shared a common coding environment 
at LINUX, which we are able to run the same code (with openGL). However, I'm still disappointed in the progress
that the group, even with all the forms of communcation available within the group, I felt that it is still hard to
coorindate without physically meeting.

	Individual learning:
Project:
	OpenGL:
		To help with the project, I went through tutorials on openGL, which are avaialble free on the web(http://www.opengl-tutorial.org/).  Although there are also of basic and helpful information within the tutorial, it is all of them are relevant towards our project. But without going through the full tutorial in sequence, it is not easy to understand the later tutorials without going through the previous parts.(I have minimal knowledge of graphics prior to this course). As such, I felt that we have overestimated our abilities to be able to create objects which move in 3D through coding within a month (just my point of view). With time also spent deciding on our project goal, and creating/understanding the math behind the b-curve. We have little time left to learn how to draw 3D images on code. On the bright side, i really enjoyed the tutorials on openGL and surely it will be useful for me in the future.
		
Physics Engine:
		I did not code much for the full physisc engine yet, but I did manage to make the ball "bounce" with constant gravity. The ball somehow lost energy in the end even though i did not write it to lose any energy. Still figuring out why but it might be some rounding error that cause the number to approach 0 after many iterations(of bounces).
	
Readings:
	I enjoyed the readings for this course a lot, especially TOS (as i've prior knowledge to C). HFC felt more a revision and overview of C. Surely i'll still have to refer to the notes to code in C and for the questions, but generally i'm familiar with C. I enjoyed reading TOS more as learning about "how computers work" is why i took up this course. TOS is really simple to read without too much overly complicated terms or codes which might indimidates me. I did not complete the TOS & HFC exercises early again mainly due to commitments form other courses as I'm taking 5 courses, I'm still trying to adapt to the workload here (compared to Singapore)

Exam Questions 
1.	 What is the average processing speed of a cpu? What is the average transfer rate (read) from memory to cpu? How do we handle the differences?

CPU:				0.5ns
SSD to Memory:	 	25us	50000 x CPU clock 
Memory to CPU:		100ns 	200 x CPU clock
CPU processing speed is much faster than the data transfer rate. In order to resolve this, the CPU is constantly processing information from different processes which reaches 
Cache first to fully utilise the processing time of the CPU. This will allow the CPU to be more efficient and faster processing time overall. 
Also, in order to improve ( by reducing ) the time it takes to reach the CPU, OS and hardware utilize different features such as block transfer, prefetching, buffering and caching 
to minimize the transfter time. (this part of the answer is similar to Q3 OF CH4)

2. 	List down the number of bits each data type occupy. 
	What would you use to store a boolean value and what would you use to store the population in China ?
int 	16
long 	32
short	~8  
float	32
double 	64
char 	8 

Boolean : 	use short, or use bool with boolean library. 
			Alternatively, if many boolean values are required to be stored, we can store it in each bit of a short/long/int, depending of the number of boolean variables.
			i.e. 32 boolean variables can be stored in a long, 16 in int and 8 in short. 
Population in china : long (32 bits - up to 4,294,967,296 )

3. 	What is the benefit of compiling programs separately, then linking at the end ?
	
Compiling programs separately (into separate object code files first) will reduce the time required	to compile by reducing the need to recompile unmodified codes. 
Linking can be done at the end where all the files are compiled and each object file is updated. For a large program, the time saving can be significant. 


HFC: 
	EX 2.5: https://github.com/chongswee/ExercisesInC/blob/master/exercises/ex02.5/find_track_complete_final.c
	EX 3: https://github.com/chongswee/ExercisesInC/blob/master/exercises/ex03/tee_cs.c
	EX 4: I read through the chapter but I had some technical difficulties executing the make file. I will surely upload the 		soltion together with the next reflection.  
TOS:
Chapter 3
// Q1-8 answered in previous reflection
	
	Running aspace.c  
Results :
1.	Address of main is 00401440
	Address of global is 0040EA24
	Address of local is 0028FF34
	Address of p is 003F0F58   
	
	Address of a is 003F0FE0  << after malloc, the address of the heap increase (grow upwards) as memory is allocated 

2. 	Address of main is 0040145C
	Address of global is 0040EA24
	Address of local is 0028FF30
	Address of p is 00A20F58

	Printing address of x - 0028FF20 << address of variable is less than local (it grows down)
	Address of a is 00A20FE0
	
3. 
		Windows 
				Address of main is 0040145C
				Address of global is 0040EA24
				Address of local is 0028FF2C
				Address of p is 007F0F58

				Address of a is 007F0FE0
				Address of i is 007F2F68 	i = malloc 10
				Address of j is 007F1068	j = malloc 21 

		LINUX 
				Address of main is 0x4005a0
				Address of global is 0x60104c
				Address of local is 0x7fff7207f48c
				Address of p is 0x1928010

				Address of a is 0x19280a0
				Address of i is 0x1928130
				Address of j is 0x1928150
		Answer : each address(for i and j) differs by 0x20 = 32 bits ! (16*2)
				
				
Chapter 4

1) What abstractions do file systems provide? Give an example of something that is logically 
	true about files systems but not true of their implementations.
	A: File abstraction - 	When you are reading a file, you are not aware of its location, or the process in which the filestream is formed.
			You are not required to know its process, but still able to use the function( or opening, reading, writing to a file etc).
	
2) What information do you imagine is stored in an OpenFileTableEntry?
	A:	OpenFileTableEntry is a class which indicates that the file is being read, and the portion which is currently being read
		Information stored:
			Line number 
			Byte number
			Read/write/rw/append -> how the file is being opened. 
			Buffer size(in memory) 
			Data left in buffer 

3) What are some of the ways operating systems deal with the relatively slow performance of persistent storage?
	A:	1. Caching 
			Keeping recent copy of data
		2. Block transfer
			Transfer more data to memory first
		3. Buffering
			Writing disc only when the buffer is full, minimizes the number of read/write from the storage.
		4. Prefetching
			Predict that the data is required and transfer before it is required.  

4) Suppose your program writes a file and prints a message indicating that it is done writing.
	A:Then a power cut crashes your computer. After you restore power and reboot the computer, you find that the file you wrote is not there. What happened? The file is is stored in memory, or buffer, which is volatile and requires power to keep the data. While storage (HDD/SSD) does not require. Hence when the power is off or when the computer crashes, all the data in the memory(or buffers) are cleared. 


5) Can you think of one advantage of a File Allocation Table over a UNIX inode? Or an advantage of a inode over a FAT?
	A: With inodes, it is easier to increase the size of the file by adding pointers to new data within the inode or indirection blcoks. 

		
6) What is overhead? What is fragmentation?
	A:"Space overhead" is data occupied by the allocator (space that is not utilised for data, but for the data structure etc.. ) 
	"Fragmentation" is when some of the blocks are only half used, - the unused space is called fragmentation (at different parts of the storagE) 

7) Why is the "everything is a file" principle a good idea? Why might it be a bad idea? ( everything is a stream )
	A: 
	Disadv: while having different files and codes, i see it as having different small "functions " and it can have different input and output. 
	The advantage of is that it is more versatile. It allows us to swap or change differernt parts of a block of code without affecting the others, 
	as they are independent. Having differnt codes will also reduce the compilation time, as only the code that is edited need to be compiled again.
	Easier to write. 

	Adv: "Everything is a file" allows quicker processing of data within the file as it is not required to transfer the data(stdout) from one code to the input(stdin) of another code.
	Hence with larger/ quicker data processing required, it might be better to write everything within a file, to speed up the processing time.  
