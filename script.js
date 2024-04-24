document.addEventListener('DOMContentLoaded', () => {
    const drp = document.querySelectorAll('.dropdown-btn');
    drp.forEach(btn => {
        btn.addEventListener('click', function() {
            this.classList.toggle('active');
        });
    });
});