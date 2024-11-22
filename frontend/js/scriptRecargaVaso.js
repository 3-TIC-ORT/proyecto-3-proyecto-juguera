const RecargaVaso = document.getElementById("recargaVaso");
RecargaVaso.addEventListener("click", async()=>{
    let colocarVaso = "confirmado"
    postData("vasoRecarga", colocarVaso);
});