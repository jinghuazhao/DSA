## Java programs

### Duan A. Bailey. **Java Structures**

http://www.cs.williams.edu/JavaStructures

### Robert Sedgewick, Kevin Wayne, **Algorithms, 4e**

https://algs4.cs.princeton.edu/home/

  * https://github.com/kevin-wayne/algs4
  * https://introcs.cs.princeton.edu/java/stdlib/
  * https://www.cs.princeton.edu/~rs/

To set up, we do
```bash
# source
git clone https://github.com/kevin-wayne/algs4
cd algs4/src/main/java/
# jars
wget https://algs4.cs.princeton.edu/code/algs4.jar
wget https://introcs.cs.princeton.edu/java/stdlib/stdlib.jar
tar xjf stdlib.jar
export CLASSPATH=$(PWD)
```
where we unjar stdlib.jar to allow for closer examination of the implementation.

**Example**

The simplest one is from the web site,
```bash
wget https://introcs.cs.princeton.edu/java/15inout/Average.java
javac Average.java
java Average
```

Now we have a go with those in algs4
```bash
# from CPM.java the location of the test file is fetched
wget https://algs4.cs.princeton.edu/44sp/jobsPC.txt
javac edu/princeton/cs/algs4/CPM.java
java  edu.princeton.cs.algs4.CPM < jobsPC.txt
```

Additionally, we can use `algs4.jar` directly,
```bash
java -cp .:algs4.jar edu.princeton.cs.algs4.FFT 2
```
