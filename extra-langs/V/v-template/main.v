
import turing_api_v

[export: 'on_load']
fn on_load() {
    msg := c"On Load!"
    turing_api_v.log(msg)
}

[export: 'on_update']
fn on_update(beat f32) {
    
}

[export: 'on_exit']
fn on_exit() {
    
}

