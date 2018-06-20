## Java programs

* Duan A. Bailey. **Java Structures**, http://www.cs.williams.edu/JavaStructures

* Robert Sedgewick, Kevin Wayne, **Algorithms, 4e**, https://algs4.cs.princeton.edu/home/
  * https://github.com/kevin-wayne/algs4
  * https://introcs.cs.princeton.edu/java/stdlib/
  * https://www.cs.princeton.edu/~rs/

**Example**

The simplest one is from the web site,
```bash
wget https://introcs.cs.princeton.edu/java/15inout/Average.java
javac Average.java
java Average
```

Now we have a go with those in algs4
```bash
git clone https://github.com/kevin-wayne/algs4
wget https://introcs.cs.princeton.edu/java/stdlib/stdlib.jar
cd algs4/src/main/java/
tar xjf stdlib.jar
export CLASSPATH=$(PWD)
wget https://algs4.cs.princeton.edu/44sp/jobsPC.txt
javac edu/princeton/cs/algs4/CPM.java
java  edu.princeton.cs.algs4.CPM < jobsPC.txt
```
