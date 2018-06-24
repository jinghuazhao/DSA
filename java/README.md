## Java

We start with [Average.java](https://introcs.cs.princeton.edu/java/15inout/Average.java),
```bash
wget https://introcs.cs.princeton.edu/java/15inout/Average.java
javac Average.java
java Average
```
and continue with four references.

### 1. Bailey DA (2007). **Java Structures**, sqrt(7)e, http://www.cs.williams.edu/JavaStructures/Book_files/JavaStructures.pdf.

http://www.cs.williams.edu/JavaStructures and http://www.cs.williams.edu/~bailey/JavaStructures/JS-site.tgz

This is the simpler of the two in terms of setup.

```bash
wget http://www.cs.williams.edu/JavaStructures/Software_files/bailey.jar
wget http://www.cs.williams.edu/JavaStructures/Software_files/structure-source.tgz
wget http://www.cs.williams.edu/JavaStructures/Examples_files/structure-examples.tgz
```
We run `Sort.java` from `structure-examples.tgz`,
```bash
tar fvzx structure-examples.tgz
cp eg/structure5/Sort.java .
javac Sort.java
java -cp .:bailey.jar Sort
```
and type a list of numbers to the console and end with Ctrl-D to get the sorted sequence.

### 2. Sedgewick R, Wayne K (2011), **Algorithms, 4e**, Pearson.

https://algs4.cs.princeton.edu/home/

The following URLs also contain relevant information
  * https://github.com/kevin-wayne/algs4
  * https://introcs.cs.princeton.edu/java/stdlib/
  * https://www.cs.princeton.edu/~rs/

The jar files can be used directly,
```bash
wget https://algs4.cs.princeton.edu/code/algs4.jar
wget https://introcs.cs.princeton.edu/java/stdlib/stdlib.jar
java -cp .:algs4.jar:stdlib.jar edu.princeton.cs.algs4.FFT 2
export wd=$(PWD)
```
where we note down the working directory (`wd`) and to closely examine the code, we do
```bash
git clone https://github.com/kevin-wayne/algs4
cd algs4
mvn package
cd src/main/java/
wget https://algs4.cs.princeton.edu/44sp/jobsPC.txt
javac edu/princeton/cs/algs4/CPM.java
java -cp .:$wd/stdlib.jar edu.princeton.cs.algs4.CPM < jobsPC.txt
```
where `mvn package` builds `algs4-1.0.0.0.jar` through `maven` to the target/ directory whose content can be listed with `jar tvf` just as `tar tvf`.

### 3. Goodrich MT, Tamassia R, Goldwasser MH (2014). Data Structures and Algorithms in Java, 6e. Wiley.

https://www.wiley.com/en-us/Data+Structures+and+Algorithms+in+Java%2C+6th+Edition-p-9781118803141

which is in accordance with its C++ and Python counterpart.

### 4. Koffman EB, Wolfgang PAT (2016). Data Structures, Abstraction and Design Using Java, 3e. Wiley.

https://www.wiley.com/en-us/Data+Structures,+Abstraction+and+Design+Using+Java,+3rd+Edition-p-9781119239147

which is more recent.
