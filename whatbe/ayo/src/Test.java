class Test
{
    static int a;
    Test(int x){
        System.out.println("HELP MEAHH");
    }
    Test(){
        this(10);
    }
    public void a(){

    }   
       
    private static void a(int x){

    }
    

    public static void main(String[] args) {
      System.out.println(func());



      String a= "hello";
      String b = new String("hello");
      System.out.println(a == b);
    }
    public static int func(){
        int x = 10;
        try{
            x= 0/x;
        }catch(Exception e){return x;}
        return 500;
    }
    
}



abstract class Animal{
    int age;
    Animal(int age){
        this.age = age;
    }
    public void eat(){
        System.out.println("eating...");
    }
}
class cat extends Animal{
    int maxlife;
    cat(int age, int maxlife){
        super(age);
        this.maxlife = maxlife;
    }


}



// 