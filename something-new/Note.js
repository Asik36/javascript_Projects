export default class Note{
    constructor(dirc ,runningTime,time){
    setTimeout(()=>{
    this.runningTime = runningTime;
    this.dirc = dirc;
    this.bool = false;
    this.elem = document.createElement("div");
    this.velocity = 400/this.runningTime; //pixels per second
    var newX = document.getElementById("dot_"+dirc).style.width;
    this.newTime = this.velocity/(400-newX);
    console.log("time: "+ this.runningTime , " clickWindow: " ,this.newTime , " velocity: "+ this.velocity);

    this.appendelem();

    this.elem.addEventListener('animationend', () => {this.remove();});

    this.startAnimation();

    }, time*1000);
    }
    appendelem() {
        this.elem.classList.add("Note");
        document.getElementById('dot_' + this.dirc).append(this.elem);
    }
    startAnimation(){
        setTimeout(() =>{this.bool = true;},this.runningTime*1000-this.newTime*1000);
        this.elem.style.animation = this.dirc+" "+this.runningTime+"s linear";
    }
    remove() {
        this.elem.remove();
        this.bool = false;
        delete this;
    }



}