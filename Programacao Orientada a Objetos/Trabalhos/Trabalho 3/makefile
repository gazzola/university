JFLAGS = -g
JC = javac
JVM = java
RM = rm -f

MAIN = LoginWindow
CLASSES = \
		CreateObjectFile.java \ 
		RegistryFunctionary.java \ 
		CreateTextFile.java \ 
		RegistrySupporter.java \ 
		EmptyFieldException.java \ 
		SupporterAlreadyRegisteredException.java \ 
		FileAction.java \ 
		SupporterEditWindow.java \ 
		FileException.java \ 
		Supporter.java \ 
		FileType.java \ 
		SupporterRegisterWindow.java \ 
		LoginWindow.java \ 
		SupporterReportWindow.java \ 
		NegativeNumberException.java \ 
		SupporterWindow.java \ 
		ObjectFile.java \ 
		SystemLog.java \ 
		ReadObjectFile.java \ 
		TextFile.java \ 
		ReadTextFile.java


all: default

.SUFFIXES: .java .class

.java.class:
	$(JC) $(JFLAGS) $*.java

default: classes

classes: $(CLASSES:.java=.class)

run:
	$(JVM) $(MAIN)

clean:
	$(RM) *.class