## Java programs

The simplest one is from the web site,
```bash
wget https://introcs.cs.princeton.edu/java/15inout/Average.java
javac Average.java
java Average
```
We now turn to two references.

### Duan A. Bailey. **Java Structures**

http://www.cs.williams.edu/JavaStructures

### Robert Sedgewick, Kevin Wayne, **Algorithms, 4e**

https://algs4.cs.princeton.edu/home/

  * https://github.com/kevin-wayne/algs4
  * https://introcs.cs.princeton.edu/java/stdlib/
  * https://www.cs.princeton.edu/~rs/

As for the algorithms, we can start with precompiled versions,
```bash
wget https://algs4.cs.princeton.edu/code/algs4.jar
wget https://introcs.cs.princeton.edu/java/stdlib/stdlib.jar
java -cp .:algs4.jar:stdlib.jar edu.princeton.cs.algs4.FFT 2
```
and for closer examination of the implementation, we do
```bash
# source
git clone https://github.com/kevin-wayne/algs4
cd algs4/src/main/java/
# jars
tar xjf stdlib.jar
export CLASSPATH=$(PWD)
```
Now we have a go with `CPM.java`
```bash
# from CPM.java the location of the test file is fetched
wget https://algs4.cs.princeton.edu/44sp/jobsPC.txt
javac edu/princeton/cs/algs4/CPM.java
java  edu.princeton.cs.algs4.CPM < jobsPC.txt
```

Lastly, we could build `algs4-1.0.0.0.jar` with maven, i.e., `mvn` so the much desired .jar is in the target/ directory whose content can be listed with `jar tvf` just as `tar tvf`.
