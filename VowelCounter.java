import java.util.Scanner; //this is needed to utilize scanner a imput from keyboard built in function

public class VowelCounter{ //You define a public class which holds all the elements
    public static void main(String[] args){ //main function contains all driver code
      int countA = 0;int countE = 0;int countI = 0;int countO = 0;int countU = 0; //Declareing all variables that will be used in the program
      System.out.println("Enter a sentence: ");
      Scanner input = new Scanner(System.in); //creating a new scanner named input for later use
      String sentence = input.nextLine(); //assigning value sentence an input line using scanner
      for(int i=0; i<sentence.length(); i++){ //iterating through a loop 
        char c = sentence.charAt(i); //this is more effieicnt than .substring() it treats the entire string like an array (kinda)
        if(c=='a' || c=='A') countA++; //this is the comparing section little easier than using if else... also doesnt worry about case as || is essentiall an or statement
        if(c=='e' || c=='E') countE++;
        if(c=='i' || c=='I') countI++;
        if(c=='o' || c=='O') countO++;
        if(c=='u' || c=='U') countU++;}

      System.out.format("A  |%3d\n", countA); //prints everything out if the format is needed to be something like ##3 instead of blank
      System.out.format("E  |%3d\n", countE); //spaces do a quick search to figure out how to modify the formatting.
      System.out.format("I  |%3d\n", countI);
      System.out.format("O  |%3d\n", countO);
      System.out.format("U  |%3d\n", countU);
    input.close();}}

/*String phrase = input.next();
System.out.print("A |");

  for (int a = 0; a < phrase.length(); a++)
    if (phrase.substring(a,a+1).equalsIgnoreCase("a")) {
      aCounter++;
    }
  for (int i = 0; i < aCounter; i++) {
  if (i != aCounter + 1) {
    System.out.print("#");
   }
   else {
     System.out.print(aCounter);
   }     */