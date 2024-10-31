const recipiente = document.getElementById("recipiente");
recipiente.addEventListener("click", async()=>{
    let confirmadoRecipiente = "confirmado"
    postData("Recipiente", confirmadoRecipiente);
})