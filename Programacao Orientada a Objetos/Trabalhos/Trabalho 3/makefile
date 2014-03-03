JFLAGS = -g
JC = javac
JVM = java
RM = rm -f

MAIN = LoginWindow
CLASSES = \
		EmptyFieldException.java \
		LoginWindow.java \
		NegativeNumberException.java \
		RegistryFunctionary.java \
		RegistrySupporter.java \
		Supporter.java \
		SupporterAlreadyRegisteredException.java \
		SupporterEditWindow.java \
		SupporterRegisterWindow.java \
		SupporterReportWindow.java \
		SupporterWindow.java


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