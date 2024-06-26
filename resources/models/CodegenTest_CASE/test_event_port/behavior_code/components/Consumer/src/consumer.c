#include <camkes.h>
#include <stdio.h>
#include <sb_consumer_impl.h>

static int8_t _value;

void test_event_port_consumer_component_init(const int64_t *in_arg) {
  printf("[%s] test_event_port_consumer_component_init called\n", get_instance_name());
  _value = 0;
}

void test_event_port_consumer_s_event_handler() {
  int8_t old_value = _value;
  while(sb_s_dequeue()) {
    _value = (_value + 1) % 500;
  }
  
  printf("[%s] Callback fired.  Received %i events this dispatch, %i total\n", get_instance_name(), (_value - old_value), _value);
}
