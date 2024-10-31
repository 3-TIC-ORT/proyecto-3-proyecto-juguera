const RecargaPolvo = document.getElementById("recargaPolvo");
RecargaPolvo.addEventListener("click", async()=>{
    let colocarPolvo = "confirmado"
    postData("vasoConcentrado", colocarPolvo);
});