const RecargaRevolver = document.getElementById("recargaRevolver");
RecargaRevolver.addEventListener("click", async()=>{
    let RecipienteRevolver = "confirmado"
    postData("recipienteRevolver", RecipienteRevolver);
});