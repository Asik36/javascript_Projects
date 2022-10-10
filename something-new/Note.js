export default class Note{
    constructor(dirc ,runningTime, delay){
    
    this.runningTime = (runningTime)*1000;
    this.dirc = dirc;
    this.bool = false;
    this.velocity = 400/this.runningTime; //pixels per milisecond
    var newX = 75;
    this.newTime = (400-newX)/this.velocity;
    this.startTime = Date.now();

    // clock = 102102
    // arrive at clock = 11000
    // bad click at clock 11000-100
    // avarage click at clokc 11000-50
    // great click at clock 11000-(20/0)


    this.elem = document.createElement("div");
    console.log("newX:" + newX,"runningTime: "+ this.runningTime
     , " clickWindow: " ,this.newTime , " velocity: "+ this.velocity);
    this.appendelem();

    this.elem.addEventListener('animationend', () => {this.remove();});

    this.startAnimation();

    }
    appendelem() {
        this.elem.classList.add("Note");
        document.getElementById('dot_' + this.dirc).append(this.elem);
    }
    startAnimation(){
        this.elem.style.animation = this.dirc+" "+this.runningTime/1000+"s linear";
    }
    remove() {
        this.elem.remove();
        this.bool = false;
        delete this;
    }



}